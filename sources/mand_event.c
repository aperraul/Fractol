/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:12:26 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/01 15:56:35 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

int				ft_mandel_mouse(int btn, int x, int y, t_frac *frac)
{
	frac->btn = btn;
	frac->cursor = ft_make_pt(x, y);
	if (btn == 1 || btn == 5)
		frac->key = 24;
	else if (btn == 2 || btn == 4)
		frac->key = 27;
	ft_mandelbrot(frac);
	frac->btn = -1;
	frac->key = -1;
	return (0);
}

int				ft_mand_event(int keycode, t_frac *frac)
{
	if (keycode == 53)
	{
		ft_free_frac(frac);
		exit(0);
	}
	frac->key = keycode;
	ft_mandelbrot(frac);
	return (0);
}
