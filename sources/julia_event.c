/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:12:26 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/26 14:51:07 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

int				ft_julia_mouse(int btn, int x, int y, t_frac *frac)
{
	x = 1;
	y = 1;
	frac->cursor = ft_make_ptll(WIN_X / 2, WIN_Y / 2);
	if (btn == 1 || btn == 5)
		frac->key = 24;
	else if (btn == 2 || btn == 4)
		frac->key = 27;
	ft_julia(frac);
	return (0);
}

int				ft_jul_mouse(int x, int y, t_frac *frac)
{
	if (x >= 0 && x <= WIN_X && y >= 0 && y <= WIN_Y)
	{
		frac->cursor_x = (x * 2 - WIN_X);
		frac->cursor_y = (y * 2 - WIN_Y);
		ft_julia(frac);
	}
	return (1);
}

int				ft_jul_event(int keycode, t_frac *frac)
{
	if (keycode == 53)
	{
		ft_free_frac(frac);
		exit(0);
	}
	frac->key = keycode;
	ft_julia(frac);
	return (0);
}
