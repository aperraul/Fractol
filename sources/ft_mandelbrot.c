/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:16:31 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/18 16:41:11 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

t_mand	*ft_mand_init(t_mand *mand);

void	ft_mandelbrot(t_fract *fract)
{
	t_mand	*mand;
	t_mlx	*mlx;

	mlx = NULL;
	mlx = ft_mlx_init(mlx, fract->size.x, fract->size.y, fract->title);
	mand = ft_mand_init(mand);
}
