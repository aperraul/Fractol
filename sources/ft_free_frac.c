/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_frac.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:51:15 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/01 15:52:46 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

void	ft_free_frac(t_frac *frac)
{
	if (frac->mlx)
		ft_clear_mlx(frac->mlx);
	ft_memdel((void **)&frac);
}
