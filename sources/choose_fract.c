/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:22:10 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/02 16:11:51 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

void	ft_choose_fract(char *title)
{
	if (!ft_strcmp(title, "Mandelbrot"))
		ft_pre_mandelbrot(title);
	else if (!ft_strcmp(title, "Julia"))
		ft_pre_julia(title);
	else if (!ft_strcmp(title, "Newton"))
		ft_pre_newton(title);
	else
	{
		ft_putstr("usage: ./Fractol Mandelbrot\n");
		ft_putstr("       ./Fractol Julia\n");
		ft_putstr("       ./Fractol Newton\n");
	}
}
