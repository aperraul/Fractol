/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:24:15 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/30 17:20:39 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

static void		ft_free_color_tab(t_jul *jul)
{
	if (jul->color_tab)
		ft_memdel((void **)&jul->color_tab);
}

static void		ft_julia_color(t_jul *jul)
{
	int		hexmin;
	int		i;

	jul->color_tab = (int *)ft_memalloc(sizeof(int) * jul->nmax);
	hexmin = (0xFFFFFF / jul->nmax);
	i = -1;
	while (++i < jul->nmax)
		jul->color_tab[i] = hexmin + (hexmin * i);
}

static void		ft_image_init(t_jul *jul)
{
	int		image_x;
	int		image_y;

	image_x = (jul->x2 - jul->x1) * jul->zoom;
	image_y = (jul->y2 - jul->y1) * jul->zoom;
	jul->pmax.x = image_x - ((image_x - WIN_X) / 2);
	jul->pmax.y = image_y - ((image_y - WIN_Y) / 2);
	jul->pmin.x = (image_x - WIN_X) / 2;
	jul->pmin.y = (image_y - WIN_Y) / 2;
	ft_julia_color(jul);
}

static int		ft_julia_loops(t_jul *jul, t_pt p, float z, int i)
{
	double	tmp;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	c_r = jul->cursor_x / 1000;
	c_i = jul->cursor_y / 1000;
	z_r = (float)((float)(p.x + jul->pmin.x + jul->pos.x) / z) + (jul->x1);
	z_i = (float)((float)(p.y + jul->pmin.y + jul->pos.y) / z) + (jul->y1);
	i = -1;
	while ((z_r * z_r) + (z_i * z_i) < 4 && ++i < jul->nmax)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = (2 * z_i * tmp) + c_i;
	}
	return (i);
}

void			ft_julia(t_jul *jul)
{
	t_pt	p;
	int		i;

	ft_reset_img(jul->mlx, 0);
	ft_jul_zoom_mode(jul);
	ft_image_init(jul);
	p.x = 0;
	jul->index.x = jul->pmin.x - 1;
	while (++jul->index.x < jul->pmax.x)
	{
		p.y = 0;
		jul->index.y = jul->pmin.y - 1;
		while (++jul->index.y < jul->pmax.y)
		{
			i = ft_julia_loops(jul, p, jul->zoom, i);
			if (i == jul->nmax)
				ft_draw_pixel(jul->mlx, 0xFFFFFF, p);
			else
				ft_draw_pixel(jul->mlx, jul->color_tab[i], p);
			p.y++;
		}
		p.x++;
	}
	ft_free_color_tab(jul);
	ft_flush_img(jul->mlx);
}
