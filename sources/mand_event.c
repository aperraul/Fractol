/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:12:26 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/29 12:57:33 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

static void		ft_calc_pos(t_mand *mand)
{
	mand->pos.x += (mand->cursor.x * 2 - WIN_X) / 2;
	mand->pos.y += (mand->cursor.y * 2 - WIN_Y) / 2;
}

void	ft_zoom_mode(t_mand *mand)
{
	if (mand->key == 24 || mand-> key == 27)
	{
		if (mand->key == 24)
		{
			if (mand->btn == 1 || mand->btn == 5)
				ft_calc_pos(mand);
			mand->zoom *= THEZOOM;
			mand->pos.x *= THEZOOM;
			mand->pos.y *= THEZOOM;
			mand->nmax *= ITERATOR;
			mand->zoomf++;
		}
		else
		{
			if (!mand->zoomf)
			{
				mand->pos = ft_make_pt(0, 0);
				return ;
			}
			if (mand->btn == 2 || mand->btn == 4)
				ft_calc_pos(mand);
			mand->zoom /= THEZOOM;
			mand->pos.x /= THEZOOM;
			mand->pos.y /= THEZOOM;
			mand->nmax /= ITERATOR;
			mand->zoomf--;
		}
	}
}

int		ft_mandel_mouse(int btn, int x, int y, t_mand *mand)
{
	mand->btn = btn;
	mand->cursor = ft_make_pt(x, y);
	if (btn == 1 || btn == 5)
		mand->key = 24;
	else if (btn == 2 || btn == 4)
		mand->key = 27;
	ft_mandelbrot(mand);
	mand->btn = -1;
	return (0);
}

int		ft_mand_event(int keycode, t_mand *mand)
{
	if (keycode == 53)
		exit(0);
	mand->key = keycode;
	ft_mandelbrot(mand);
	return (0);
}
