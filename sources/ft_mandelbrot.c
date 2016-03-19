/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:16:31 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/19 16:36:08 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

t_mand	*ft_mand_init(t_mand *mand, t_fract *fract)
{
	mand = (t_mand *)ft_memalloc(sizeof(t_mand));
	mand->x1 = -2.6;
	mand->y1 = -1.2;
	mand->x2 = 0.6;
	mand->y2 = 1.2;
	mand->nmax = 50;
	mand->zoom = 100;
	return (mand);
}

void	ft_mandelbrot(t_fract *fract)
{
	t_mand	*mand;
	t_mlx	*mlx;

	mlx = NULL;
	mand = NULL;
	mlx = ft_mlx_init(mlx, fract->size.x, fract->size.y, fract->title);
	mand = ft_mand_init(mand, fract);
	ft_do_mandelbrot(mlx, mand);
}
