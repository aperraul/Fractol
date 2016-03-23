/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mand_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:12:26 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/23 15:25:05 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

void	ft_zoom_mode(t_mand *mand)
{
	if (mand->key == 24 || mand-> key == 27)
	{
		if (mand->key == 24)
			mand->zoom += 10;
		else
			mand->zoom -= 10;
	}
}

int		ft_mand_event(int keycode, t_mand *mand)
{
	if (keycode == 53)
		exit(0);
	mand->key = keycode;
	ft_mandelbrot(mand);
	return (0);
}
