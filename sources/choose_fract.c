/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:22:10 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/01 15:48:52 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

void	ft_choose_fract(char *title)
{
	if (!ft_strcmp(title, "Mandelbrot"))
		ft_pre_mandelbrot(title);
	else if (!ft_strcmp(title, "Julia"))
		ft_pre_julia(title);
//	else if (!ft_strcmp(title, "B.S.Mandelbrot"))
//		ft_pre_bs_mandelbrot(title);
	else
	{
		ft_putstr("usage: ./Fractol Mandelbrot\n");
		ft_putstr("       ./Fractol Julia\n");
		ft_putstr("       ./Fractol B.S.Mandelbrot\n");
	}
}
