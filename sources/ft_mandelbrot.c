/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:24:15 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/21 17:18:35 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

t_mand	*ft_mand_img(t_mand *mand)
{
	mand->image_x = (mand->x2 - mand->x1) * mand->zoom;
	mand->image_y = (mand->y2 - mand->y1) * mand->zoom;
	return (mand);
}

void	ft_mandelbrot(t_mlx *mlx, t_mand *mand)
{	int		x;
	int		y;
	int		i;
	double	tmp;

	mand = ft_mand_img(mand);
	x = -1;
	while (++x < mand->image_x)
	{
		y = -1;
		while (++y < mand->image_y)
		{
			mand->c_r = (float)((float)x / (float)mand->zoom) + mand->x1;
			mand->c_i = (float)((float)y / (float)mand->zoom) + mand->y1;
			mand->z_r = 0;
			mand->z_i = 0;
			i = -1;
			while ((mand->z_r * mand->z_r) + (mand->z_i * mand->z_i) < 4 &&
					++i < mand->nmax)
			{
				tmp = mand->z_r;
				mand->z_r = (mand->z_r * mand->z_r) - (mand->z_i * mand->z_i)
					+ mand->c_r;
				mand->z_i = (2 * mand->z_i * tmp) + mand->c_i;
			}
			if (i == mand->nmax)
				ft_draw_pixel(mlx, 0xFFFFFF, ft_make_pt(x, y));
			else
				ft_draw_pixel(mlx, 0x136576, ft_make_pt(x, y));
		}
	}
	ft_flush_img(mlx);
	mlx_loop(mlx);
}
