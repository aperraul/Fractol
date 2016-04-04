/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_newton.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:16:31 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/04 12:44:34 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

t_frac			*ft_newt_init(t_frac *frac, t_mlx *mlx)
{
	frac = (t_frac *)ft_memalloc(sizeof(t_frac));
	frac->mlx = mlx;
	frac->pos = ft_make_pt(0, 0);
	frac->pmin = ft_make_pt(0, 0);
	frac->pmax = ft_make_pt(0, 0);
	frac->cursor_x = 0;
	frac->cursor_y = 0;
	frac->x1 = -1;
	frac->y1 = -1.2;
	frac->x2 = 1;
	frac->y2 = 1.2;
	frac->btn = -1;
	frac->nmax = 40;
	frac->zoom = (WIN_X / (frac->x2 - frac->x1));
	frac->color_tab = NULL;
	frac->zoomf = 0;
	return (frac);
}

void			ft_pre_newton(char *title)
{
	t_frac	*frac;
	t_mlx	*mlx;

	mlx = NULL;
	frac = NULL;
	mlx = ft_mlx_init(mlx, WIN_X, WIN_Y, title);
	frac = ft_newt_init(frac, mlx);
	ft_newton(frac);
	mlx_hook(frac->mlx->p_win, KeyPress, KeyPressMask, ft_newt_event, frac);
	mlx_mouse_hook(frac->mlx->p_win, ft_newton_mouse, frac);
	mlx_loop(frac->mlx->p_mlx);
}
