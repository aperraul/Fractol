/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:24:15 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/26 14:41:08 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

static int		ft_julia_loops(t_frac *frac, t_pt p, float z, int i)
{
	double	tmp;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	c_r = frac->cursor_x / 1000;
	c_i = frac->cursor_y / 1000;
	z_r = (double)((double)(p.x + frac->pmin.x + frac->pos.x) / z) + (frac->x1);
	z_i = (double)((double)(p.y + frac->pmin.y + frac->pos.y) / z) + (frac->y1);
	i = -1;
	while ((z_r * z_r) + (z_i * z_i) < 4 && ++i < frac->nmax)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = (2 * z_i * tmp) + c_i;
	}
	return (i);
}

void			ft_julia(t_frac *frac)
{
	t_pt	p;
	int		i;

	ft_reset_img(frac->mlx, 0);
	ft_frac_zoom_mode(frac);
	ft_image_init(frac);
	p.x = 0;
	frac->index.x = frac->pmin.x - 1;
	while (++frac->index.x < frac->pmax.x)
	{
		p.y = 0;
		frac->index.y = frac->pmin.y - 1;
		while (++frac->index.y < frac->pmax.y)
		{
			i = ft_julia_loops(frac, p, frac->zoom, i);
			if (i == frac->nmax)
				ft_draw_pixel(frac->mlx, 0xFFFFFF, p);
			else
				ft_draw_pixel(frac->mlx, frac->color_tab[i], p);
			p.y++;
		}
		p.x++;
	}
	ft_free_color_tab(frac);
	ft_flush_img(frac->mlx);
}
