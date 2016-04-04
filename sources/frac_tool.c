/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:18:13 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/04 12:47:12 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

static void		ft_calc_pos(t_frac *frac)
{
	frac->pos.x += (frac->cursor.x * 2 - WIN_X) / 2;
	frac->pos.y += (frac->cursor.y * 2 - WIN_Y) / 2;
}

void			ft_frac_zoom_mode(t_frac *frac)
{
	if (frac->key == 24 || frac->key == 27)
	{
		if (frac->key == 24)
		{
			if (frac->btn == 1 || frac->btn == 5)
				ft_calc_pos(frac);
			ft_incrementator(frac, 1);
		}
		else
		{
			if (!frac->zoomf)
			{
				frac->pos = ft_make_pt(0, 0);
				return ;
			}
			if (frac->btn == 2 || frac->btn == 4)
				ft_calc_pos(frac);
			ft_incrementator(frac, 2);
		}
	}
}

void			ft_free_color_tab(t_frac *frac)
{
	if (frac->color_tab)
		ft_memdel((void **)&frac->color_tab);
}

void			ft_frac_color(t_frac *frac)
{
	int		hexmin;
	int		i;

	if (frac->key == 78)
		frac->t++;
	if (frac->key == 69)
		frac->t--;
	if (frac->t < 1)
		frac->t = 1;
	frac->color_tab = (int *)ft_memalloc(sizeof(int) * frac->nmax);
	hexmin = (0xFFFFFF / frac->nmax + frac->t);
	i = -1;
	while (++i < frac->nmax)
		frac->color_tab[i] = hexmin + (hexmin * i);
}

void			ft_incrementator(t_frac *frac, int mode)
{
	if (mode == 1)
	{
		frac->zoom *= THEZOOM;
		frac->pos.x *= THEZOOM;
		frac->pos.y *= THEZOOM;
		frac->nmax *= ITERATOR;
		frac->zoomf++;
	}
	else if (mode == 2)
	{
		frac->zoom /= THEZOOM;
		frac->pos.x /= THEZOOM;
		frac->pos.y /= THEZOOM;
		frac->nmax /= ITERATOR;
		if (frac->nmax < 40)
			frac->nmax = 40;
		frac->zoomf--;
	}
}
