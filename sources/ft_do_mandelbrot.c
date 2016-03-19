/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:24:15 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/19 17:07:53 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

void	ft_do_mandelbrot(t_mlx *mlx, t_mand *mand)
{	int		x;
	int		y;
	int		i;
	double	tmp;

	mand->image_x = (mand->x2 - mand->x1) * mand->zoom;
	mand->image_y = (mand->y2 - mand->y1) * mand->zoom;
	x = -1;
	while (++x < mand->image_x)
	{
		y = -1;
		while (++y < mand->image_y)
		{
			mand->c_r = x / mand->zoom + mand->x1;
			mand->c_i = y / mand->zoom + mand->y1;
			mand->z_r = 0;
			mand->z_i = 0;
			i = -1;
			while (mand->z_r * mand->z_r + mand->z_i * mand->z_i < 4 &&
					++i < mand->nmax)
			{
				tmp = mand->z_r;
				mand->z_r = mand->z_r * mand->z_r - mand->z_i * mand->z_i
					+ mand->c_r;
				mand->z_i = 2 * mand->z_i * tmp + mand->c_i;
			}
			if (i == mand->nmax)
				//draw pixel noir;
			else
				//draw pixel color rn fct de i;
		}
	}
}
