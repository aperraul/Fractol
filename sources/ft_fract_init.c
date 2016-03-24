/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:34:21 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/24 11:16:44 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

t_fract		*ft_fract_init(t_fract *fract, char *str)
{
	fract = (t_fract *)ft_memalloc(sizeof(t_fract));
	fract->mlx = NULL;
	fract->size.x = WIN_X;
	fract->size.y = WIN_Y;
	fract->title = str;
	return (fract);
}

t_fract		*ft_free_fract(t_fract *fract)
{
	ft_memdel((void **)fract);
	return (fract);
}
