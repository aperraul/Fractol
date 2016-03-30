/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:22:10 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/30 12:10:21 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

void	ft_choose_fract(t_fract *fract)
{
	if (!ft_strcmp(fract->title, "Mandelbrot"))
		ft_pre_mandelbrot(fract);
//	else if (!ft_strcmp(fract->title, "Julia"))
//		ft_julia(fract);
	else
	{
		ft_putstr("usage: ./Fractol Mandelbrot\n");
		ft_putstr("       ./Fractol Julia\n");
		ft_putstr("       ./Fractol (le dernier putin de fractal au choix)\n");
	}
	fract = ft_free_fract(fract);
}
