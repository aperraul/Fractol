/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:24:15 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/04 13:16:19 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

void			ft_image_init(t_frac *frac)
{
	int		image_x;
	int		image_y;

	image_x = (frac->x2 - frac->x1) * frac->zoom;
	image_y = (frac->y2 - frac->y1) * frac->zoom;
	frac->pmax.x = image_x - ((image_x - WIN_X) / 2);
	frac->pmax.y = image_y - ((image_y - WIN_Y) / 2);
	frac->pmin.x = (image_x - WIN_X) / 2;
	frac->pmin.y = (image_y - WIN_Y) / 2;
	ft_frac_color(frac);
}

static int		ft_mandel_loops(t_frac *frac, t_pt p, float z, int i)
{
	double	tmp;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	c_r = (double)((double)(p.x + frac->pmin.x + frac->pos.x) / z) + (frac->x1);
	c_i = (double)((double)(p.y + frac->pmin.y + frac->pos.y) / z) + (frac->y1);
	z_r = 0;
	z_i = 0;
	i = -1;
	while ((z_r * z_r) + (z_i * z_i) < 4 && ++i < frac->nmax)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = (2 * z_i * tmp) + c_i;
	}
	return (i);
}

static int		ft_mandelbs_loops(t_frac *frac, t_pt p, float z, int i)
{
	double	tmp;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	c_r = (double)((double)(p.x + frac->pmin.x + frac->pos.x) / z) + (frac->x1);
	c_i = (double)((double)(p.y + frac->pmin.y + frac->pos.y) / z) + (frac->y1);
	z_r = 0;
	z_i = 0;
	i = -1;
	while ((z_r * z_r) + (z_i * z_i) < 4 && ++i < frac->nmax)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = (2 * fabs(z_i * tmp)) + c_i;
	}
	return (i);
}

void			ft_mandelbrot(t_frac *frac)
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
			i = ft_mandel_loops(frac, p, frac->zoom, i);
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

void			ft_mandelbs(t_frac *frac)
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
			i = ft_mandelbs_loops(frac, p, frac->zoom, i);
			if (i == frac->nmax)
				ft_draw_pixel(frac->mlx, 0xFF0000, p);
			else
				ft_draw_pixel(frac->mlx, frac->color_tab[i], p);
			p.y++;
		}
		p.x++;
	}
	ft_free_color_tab(frac);
	ft_flush_img(frac->mlx);
}
