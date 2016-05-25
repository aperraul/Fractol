/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:12:26 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/25 11:18:25 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

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
