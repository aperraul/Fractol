/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:16:31 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/30 16:39:06 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

void	ft_free_jul(t_jul *jul)
{
	if (jul->mlx)
		ft_clear_mlx(jul->mlx);
	ft_memdel((void **)&jul);
}

t_jul	*ft_jul_init(t_jul *jul, t_mlx *mlx)
{
	jul = (t_jul *)ft_memalloc(sizeof(t_jul));
	jul->mlx = mlx;
	jul->pos = ft_make_pt(0, 0);
	jul->pmin = ft_make_pt(0, 0);
	jul->pmax = ft_make_pt(0, 0);
	jul->cursor = ft_make_pt(0, 0);
	jul->x1 = -1;
	jul->y1 = -1.2;
	jul->x2 = 1;
	jul->y2 = 1.2;
	jul->btn = -1;
	jul->nmax = 40;
	jul->zoom = (WIN_X / (jul->x2 - jul->x1));
	jul->color_tab = NULL;
	jul->zoomf = 0;
	return (jul);
}

void	ft_pre_julia(char *title)
{
	t_jul	*jul;
	t_mlx	*mlx;

	mlx = NULL;
	jul = NULL;
	mlx = ft_mlx_init(mlx, WIN_X, WIN_Y, title);
	jul = ft_jul_init(jul, mlx);
	ft_julia(jul);
	mlx_hook(jul->mlx->p_win, KeyPress, KeyPressMask, ft_jul_event, jul);
	mlx_hook(jul->mlx->p_win, MotionNotify, KeyPressMask, ft_jul_mouse, jul);
	mlx_loop(jul->mlx->p_mlx);
}
