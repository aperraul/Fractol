/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:24:15 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/30 14:11:14 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

void			ft_free_color_tab(t_mand *mand)
{
	if (mand->color_tab)
		ft_memdel((void **)&mand->color_tab);
}

static void		ft_mand_color(t_mand *mand)
{
	int		hexmin;
	int		i;

	mand->color_tab = (int *)ft_memalloc(sizeof(int) * mand->nmax);
	hexmin = (0xFFFFFF / mand->nmax);
	i = -1;
	while (++i < mand->nmax)
		mand->color_tab[i] = hexmin + (hexmin * i);
}

static void		ft_image_init(t_mand *mand)
{
	int		image_x;
	int		image_y;

	image_x = (mand->x2 - mand->x1) * mand->zoom;
	image_y = (mand->y2 - mand->y1) * mand->zoom;
	mand->pmax.x = image_x - ((image_x - WIN_X) / 2);
	mand->pmax.y = image_y - ((image_y - WIN_Y) / 2);
	mand->pmin.x = (image_x - WIN_X) / 2;
	mand->pmin.y = (image_y - WIN_Y) / 2;
	ft_mand_color(mand);
}

static int		ft_mandel_loops(t_mand *mand, t_pt p, float z, int i)
{
	double	tmp;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	c_r = (float)((float)(p.x + mand->pmin.x + mand->pos.x) / z) + (mand->x1);
	c_i = (float)((float)(p.y + mand->pmin.y + mand->pos.y) / z) + (mand->y1);
	z_r = 0;
	z_i = 0;
	i = -1;
	while ((z_r * z_r) + (z_i * z_i) < 4 && ++i < mand->nmax)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = (2 * z_i * tmp) + c_i;
	}
	return (i);
}

void			ft_mandelbrot(t_mand *mand)
{
	t_pt	p;
	int		i;

	ft_reset_img(mand->mlx, 0);
	ft_zoom_mode(mand);
	ft_image_init(mand);
	p.x = 0;
	mand->index.x = mand->pmin.x - 1;
	while (++mand->index.x < mand->pmax.x)
	{
		p.y = 0;
		mand->index.y = mand->pmin.y - 1;
		while (++mand->index.y < mand->pmax.y)
		{
			i = ft_mandel_loops(mand, p, mand->zoom, i);
			if (i == mand->nmax)
				ft_draw_pixel(mand->mlx, 0xFFFFFF, p);
			else
				ft_draw_pixel(mand->mlx, mand->color_tab[i], p);
			p.y++;
		}
		p.x++;
	}
	ft_free_color_tab(mand);
	ft_flush_img(mand->mlx);
}
