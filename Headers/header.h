/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:00:13 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/19 12:37:28 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include "../Libdraw/libdraw.h"
# include "../libmlx/X.h"

typedef struct	s_mand
{
	int			**tab;
	int			x;
	int			y;
	int			cx;
	int			cy;
	int			l;
	int			nmax;
}				t_mand;

typedef struct	s_fract
{
	t_mlx		*mlx;
	char		*title;
	t_pt		size;
}				t_fract;

t_fract			*ft_fract_init(t_fract *fract, char *str);
void			ft_choose_fract(t_fract *fract);
void			ft_mandelbrot(t_fract *fract);
t_mand			*ft_mand_init(t_mand *mand);
t_fract			*ft_free_fract(t_fract *fract);

#endif
