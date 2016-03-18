/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 13:59:13 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/18 15:48:22 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

int		main(int argc, char **argv)
{
	t_fract		*fract;

	if (argc == 2)
	{
		ft_fract_init(fract, argv[1]);
		ft_choose_fract(fract);
	}
	return (0);
}
