/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:24:15 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/25 17:35:47 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

t_mand	*ft_mand_img(t_mand *mand)
{
	int		hexmin;
	int		i;

	mand->image_x = (mand->x2 - mand->x1) * mand->zoom;
	mand->image_y = (mand->y2 - mand->y1) * mand->zoom;
	mand->color_tab = (int *)ft_memalloc(sizeof(int) * mand->nmax);
	hexmin = (0xFFFFFF / mand->nmax);
	mand->pmin.x = 0;
	mand->pmin.y = 0;
	mand->pmax.x = mand->image_x - (mand->image_x - WIN_X);
	mand->pmax.y = mand->image_y - (mand->image_y - WIN_Y);
	i = -1;
	while (++i < mand->nmax)
		mand->color_tab[i] = hexmin + (hexmin * i);
	return (mand);
}

void	ft_mandelbrot(t_mand *mand)
{
	int		x;
	int		y;
	int		i;
	double	tmp;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	ft_reset_img(mand->mlx, 0x000000);
	ft_zoom_mode(mand);
	mand = ft_mand_img(mand);
	x = -1;
	while (++x < mand->image_x && x < mand->pmax.x)
	{
		y = -1;
		while (++y < mand->image_y && y < mand->pmax.y)
		{
			if	(mand->btn == 1 && mand->cursor.x != 0 && mand->cursor.y != 0)
			{
				c_r = (float)((float)mand->cursor.x / (float)mand->zoom) + (mand->x1);
				c_i = (float)((float)mand->cursor.y / (float)mand->zoom) + (mand->y1);
				z_r = (float)(float)WIN_X / (float)mand->cursor.x;
				z_i = (float)(float)WIN_Y / (float)mand->cursor.y;
			}
			else
				c_r = (float)((float)x / (float)mand->zoom) + (mand->x1);
				c_i = (float)((float)y / (float)mand->zoom) + (mand->y1);
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
				ft_draw_pixel(mand->mlx, 0xFFFFFF, ft_make_pt(x, y));
			else
				ft_draw_pixel(mand->mlx, mand->color_tab[i], ft_make_pt(x, y));
			mand->cursor.y++;
		}
		mand->cursor.x++;
	}
	ft_flush_img(mand->mlx);
}
