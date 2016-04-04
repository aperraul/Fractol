/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:24:15 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/04 12:50:29 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

static void		ft_newt_img_init(t_frac *frac)
{
	int		image_x;
	int		image_y;

	image_x = (frac->x2 - frac->x1) * frac->zoom;
	image_y = (frac->y2 - frac->y1) * frac->zoom;
	frac->pmax.x = image_x - ((image_x - WIN_X) / 2);
	frac->pmax.y = image_y - ((image_y - WIN_Y) / 2);
	frac->pmin.x = (image_x - WIN_X) / 2;
	frac->pmin.y = (image_y - WIN_Y) / 2;
}

static t_ptd	ft_ncore(t_ptd i, double c_r, double c_i)
{
	double	tmp;
	double	xx;
	double	yy;
	float	d;

	xx = c_r * c_r;
	yy = c_i * c_i;
	d = 3.0 * ((xx - yy) * (xx - yy) + 4.0 * xx * yy);
	if (d == 0.0)
		d = 0.000001;
	tmp = c_r;
	c_r = (2.0 / 3.0) * c_r + (xx - yy) / d;
	c_i = (2.0 / 3.0) * c_i - 2.0 * tmp * c_i / d;
	i.x = c_r;
	i.y = c_i;
	return (i);
}

static t_ptd	ft_newt_loops(t_frac *frac, t_pt p, float z, t_ptd i)
{
	int		count;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	count = -1;
	c_r = (double)((double)(p.x + frac->pmin.x + frac->pos.x) / z) + (frac->x1);
	c_i = (double)((double)(p.y + frac->pmin.y + frac->pos.y) / z) + (frac->y1);
	z_r = 0;
	z_i = 0;
	while (++count < frac->nmax)
	{
		i = ft_ncore(i, c_r, c_i);
		c_r = i.x;
		c_i = i.y;
		count++;
	}
	return (i);
}

static void		ft_newt_color(t_frac *frac, t_ptd i, t_pt p)
{
	if (i.x > 0.0)
		ft_draw_pixel(frac->mlx, 0xAEEE00, p);
	else
	{
		if ((i.x < -0.3) && (i.y > 0.0))
			ft_draw_pixel(frac->mlx, 0x01B0F0, p);
		else
			ft_draw_pixel(frac->mlx, 0xFF358B, p);
	}
}

void			ft_newton(t_frac *frac)
{
	t_pt		p;
	t_ptd		i;

	ft_reset_img(frac->mlx, 0);
	ft_frac_zoom_mode(frac);
	ft_newt_img_init(frac);
	p.x = 0;
	frac->index.x = frac->pmin.x - 1;
	while (++frac->index.x < frac->pmax.x)
	{
		p.y = 0;
		frac->index.y = frac->pmin.y - 1;
		while (++frac->index.y < frac->pmax.y)
		{
			i = ft_newt_loops(frac, p, frac->zoom, i);
			ft_newt_color(frac, i, p);
			p.y++;
		}
		p.x++;
	}
	ft_flush_img(frac->mlx);
}
