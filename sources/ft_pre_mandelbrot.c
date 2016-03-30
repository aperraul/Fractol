/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:16:31 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/30 14:09:47 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

void	ft_free_mand(t_mand *mand)
{
	if (mand->mlx)
		ft_clear_mlx(mand->mlx);
	ft_memdel((void **)&mand);
}

t_mand	*ft_mand_init(t_mand *mand, t_mlx *mlx)
{
	mand = (t_mand *)ft_memalloc(sizeof(t_mand));
	mand->mlx = mlx;
	mand->pos = ft_make_pt(0, 0);
	mand->pmin = ft_make_pt(0, 0);
	mand->pmax = ft_make_pt(0, 0);
	mand->cursor = ft_make_pt(0, 0);
	mand->x1 = -2.1;
	mand->y1 = -1.2;
	mand->x2 = 0.6;
	mand->y2 = 1.2;
	mand->btn = -1;
	mand->nmax = 40;
	mand->zoom = WIN_X / (mand->x2 - mand->x1);
	mand->color_tab = NULL;
	mand->zoomf = 0;
	return (mand);
}

void	ft_pre_mandelbrot(char *title)
{
	t_mand	*mand;
	t_mlx	*mlx;

	mlx = NULL;
	mand = NULL;
	mlx = ft_mlx_init(mlx, WIN_X, WIN_Y, title);
	mand = ft_mand_init(mand, mlx);
	ft_mandelbrot(mand);
	mlx_hook(mand->mlx->p_win, KeyPress, KeyPressMask, ft_mand_event, mand);
	mlx_mouse_hook(mand->mlx->p_win, ft_mandel_mouse, mand);
	mlx_loop(mand->mlx->p_mlx);
}
