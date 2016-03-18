/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:55:55 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/12 14:51:46 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*chr;

	chr = (char *)malloc(sizeof(char) * (size + 1));
	if (chr)
		return (ft_memset(chr, 0, size + 1));
	return (NULL);
}
