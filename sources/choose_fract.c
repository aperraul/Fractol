/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:22:10 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/30 15:50:05 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

void	ft_choose_fract(char *title)
{
	if (!ft_strcmp(title, "Mandelbrot"))
		ft_pre_mandelbrot(title);
	else if (!ft_strcmp(title, "Julia"))
		ft_pre_julia(title);
	else
	{
		ft_putstr("usage: ./Fractol Mandelbrot\n");
		ft_putstr("       ./Fractol Julia\n");
		ft_putstr("       ./Fractol (le dernier putin de fractal au choix)\n");
	}
}
