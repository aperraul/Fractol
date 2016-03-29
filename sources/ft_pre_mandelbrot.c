/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:16:31 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/29 13:05:47 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

t_mand	*ft_mand_init(t_mand *mand, t_fract *fract)
{
	mand = (t_mand *)ft_memalloc(sizeof(t_mand));
	mand->mlx = fract->mlx;
	mand->pos = ft_make_pt(0, 0);
	mand->pmin = ft_make_pt(0, 0);
	mand->pmax = ft_make_pt(0, 0);
	mand->x1 = -2.1;
	mand->y1 = -1.3;
	mand->x2 = 0.6;
	mand->y2 = 1.4;
	mand->btn = -1;
	mand->nmax = 40;
	mand->cursor.x = 0;
	mand->cursor.y = 0;
	mand->zoom = WIN_X / (mand->x2 - mand->x1) + 1;
	mand->color_tab = NULL;
	mand->zoomf = 0;
	return (mand);
}

void	ft_pre_mandelbrot(t_fract *fract)
{
	t_mand	*mand;

	mand = NULL;
	fract->mlx = ft_mlx_init(fract->mlx, WIN_X, WIN_Y, fract->title);
	mand = ft_mand_init(mand, fract);
	ft_mandelbrot(mand);
	mlx_hook(fract->mlx->p_win, KeyPress, KeyPressMask, ft_mand_event, mand);
	mlx_mouse_hook(fract->mlx->p_win, ft_mandel_mouse, mand);
	mlx_loop(fract->mlx->p_mlx);
}
