/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:12:26 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/30 17:22:23 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

static void		ft_calc_pos(t_jul *jul)
{
	jul->pos.x += (jul->cursor_x * 2 - WIN_X) / 2;
	jul->pos.y += (jul->cursor_y * 2 - WIN_Y) / 2;
}

static void		ft_incrementator(t_jul *jul, int mode)
{
	if (mode == 1)
	{
		jul->zoom *= THEZOOM;
		jul->pos.x *= THEZOOM;
		jul->pos.y *= THEZOOM;
		jul->nmax *= ITERATOR;
		jul->zoomf++;
	}
	else if (mode == 2)
	{
		jul->zoom /= THEZOOM;
		jul->pos.x /= THEZOOM;
		jul->pos.y /= THEZOOM;
		jul->nmax /= ITERATOR;
		if (jul->nmax < 40)
			jul->nmax = 40;
		jul->zoomf--;
	}
}

void			ft_jul_zoom_mode(t_jul *jul)
{
	if (jul->key == 24 || jul->key == 27)
	{
		if (jul->key == 24)
		{
			if (jul->btn == 1 || jul->btn == 5)
				ft_calc_pos(jul);
			ft_incrementator(jul, 1);
		}
		else
		{
			if (!jul->zoomf)
			{
				jul->pos = ft_make_pt(0, 0);
				return ;
			}
			if (jul->btn == 2 || jul->btn == 4)
				ft_calc_pos(jul);
			ft_incrementator(jul, 2);
		}
	}
}

int				ft_jul_mouse(int x, int y, t_jul *jul)
{
	if (x >= 0 && x <= WIN_X && y >= 0 && y <= WIN_Y)
	{
		jul->cursor_x = (x * 2 - WIN_X);
		jul->cursor_y = (y * 2 - WIN_Y);
		ft_julia(jul);;
	}
	return (1);
}

int				ft_jul_event(int keycode, t_jul *jul)
{
	if (keycode == 53)
	{
		ft_free_jul(jul);
		exit(0);
	}
	jul->key = keycode;
	ft_julia(jul);
	return (0);
}
