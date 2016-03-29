/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:24:15 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/29 17:28:34 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

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
}

void	ft_mand_color(t_mand *mand)
{
	int		hexmin;
	int		i;

	mand->color_tab = (int *)ft_memalloc(sizeof(int) * mand->nmax);
	hexmin = (0xFFFFFF / mand->nmax);
	i = -1;
	while (++i < mand->nmax)
		mand->color_tab[i] = hexmin + (hexmin * i);
}

void	ft_mandelbrot(t_mand *mand)
{
	t_pt	index;
	t_pt	p;
	int		i;
	double	tmp;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	ft_reset_img(mand->mlx, 0);
	ft_zoom_mode(mand);
	ft_image_init(mand);
	ft_mand_color(mand);
	p.x = 0;
	index.x = mand->pmin.x - 1;
	while (++index.x < mand->pmax.x)
	{
		p.y = 0;
		index.y = mand->pmin.y - 1;
		while (++index.y < mand->pmax.y)
		{
			c_r = (float)((float)(p.x + mand->pmin.x + mand->pos.x) / (float)mand->zoom) + (mand->x1);
			c_i = (float)((float)(p.y + mand->pmin.y + mand->pos.y) / (float)mand->zoom) + (mand->y1);
			z_r = 0;
			z_i = 0;
			i = -1;
			while ((z_r * z_r) + (z_i * z_i) < 4 &&
					++i < mand->nmax)
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i)
					+ c_r;
				z_i = (2 * z_i * tmp) + c_i;
			}
			if (i == mand->nmax)
				ft_draw_pixel(mand->mlx, 0xFFFFFF, p);
			else
				ft_draw_pixel(mand->mlx, mand->color_tab[i], p);
			p.y++;
		}
		p.x++;
	}
	ft_flush_img(mand->mlx);
}
