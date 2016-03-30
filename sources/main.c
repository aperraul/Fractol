/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 13:59:13 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/30 14:08:46 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/header.h"

int		main(int argc, char **argv)
{
	char	*str;

	if (argc == 2)
	{
		str = argv[1];
		ft_choose_fract(str);
	}
	else
		ft_putstr("nb arguments != 1");
	return (0);
}
