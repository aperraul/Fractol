/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:34:21 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/18 15:37:48 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

t_fract		*ft_fract_init(t_fract *fract, char *str)
{
	fract->mlx = NULL;
	fract->title = str;
	fract->mend = NULL;
	return (fract);
}
