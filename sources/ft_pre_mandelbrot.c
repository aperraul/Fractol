/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:16:31 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/25 11:18:02 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

t_frac	*ft_mand_init(t_frac *frac, t_mlx *mlx)
{
	frac = (t_frac *)ft_memalloc(sizeof(t_frac));
	frac->mlx = mlx;
	frac->pos = ft_make_ptll(0, 0);
	frac->pmin = ft_make_ptll(0, 0);
	frac->pmax = ft_make_ptll(0, 0);
	frac->cursor = ft_make_ptll(0, 0);
	frac->x1 = -2.1;
	frac->y1 = -1.2;
	frac->x2 = 0.6;
	frac->y2 = 1.2;
	frac->btn = -1;
	frac->nmax = 40;
	frac->t = 1;
	frac->zoom = WIN_X / (frac->x2 - frac->x1);
	frac->color_tab = NULL;
	frac->zoomf = 0;
	return (frac);
}

void	ft_pre_mandelbrot(char *title)
{
	t_frac	*frac;
	t_mlx	*mlx;

	mlx = NULL;
	frac = NULL;
	mlx = ft_mlx_init(mlx, WIN_X, WIN_Y, title);
	frac = ft_mand_init(frac, mlx);
	ft_mandelbrot(frac);
	mlx_hook(frac->mlx->p_win, KeyPress, KeyPressMask, ft_mand_event, frac);
	mlx_mouse_hook(frac->mlx->p_win, ft_mandel_mouse, frac);
	mlx_loop(frac->mlx->p_mlx);
}

void	ft_pre_mandelbs(char *title)
{
	t_frac	*frac;
	t_mlx	*mlx;

	mlx = NULL;
	frac = NULL;
	mlx = ft_mlx_init(mlx, WIN_X, WIN_Y, title);
	frac = ft_mand_init(frac, mlx);
	ft_mandelbs(frac);
	mlx_hook(frac->mlx->p_win, KeyPress, KeyPressMask, ft_mandbs_event, frac);
	mlx_mouse_hook(frac->mlx->p_win, ft_mandelbs_mouse, frac);
	mlx_loop(frac->mlx->p_mlx);
}
