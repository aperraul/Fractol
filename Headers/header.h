/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:00:13 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/23 15:23:22 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include "../Libdraw/libdraw.h"
# include "../libmlx/X.h"

typedef struct	s_mand
{
	t_mlx		*mlx;
	int			key;
	int			*color_tab;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	int			image_x;
	int			image_y;
	int			zoom;
	int			nmax;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	t_pt		size;
}				t_mand;

typedef struct	s_fract
{
	t_mlx		*mlx;
	char		*title;
	t_pt		size;
}				t_fract;

t_fract			*ft_fract_init(t_fract *fract, char *str);
void			ft_choose_fract(t_fract *fract);
void			ft_pre_mandelbrot(t_fract *fract);
void			ft_mandelbrot(t_mand *fract);
t_mand			*ft_mand_init(t_mand *mand, t_fract *fract);
t_fract			*ft_free_fract(t_fract *fract);
int				ft_mand_event(int keycode, t_mand *mand);
void			ft_zoom_mode(t_mand *mand);

#endif
