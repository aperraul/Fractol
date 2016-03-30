/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:00:13 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/30 12:42:54 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include "../Libdraw/libdraw.h"
# include "../libmlx/X.h"

# define WIN_X 2000
# define WIN_Y 1300
# define THEZOOM 1.5
# define ITERATOR 1.12

typedef struct	s_mand
{
	t_mlx		*mlx;
	int			zoomf;
	int			key;
	int			btn;
	int			*color_tab;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		zoom;
	int			nmax;
	t_pt		pos;
	t_pt		cursor;
	t_pt		pmin;
	t_pt		pmax;
	t_pt		index;
}				t_mand;

typedef struct	s_fract
{
	t_mlx		*mlx;
	char		*title;
}				t_fract;

t_fract			*ft_fract_init(t_fract *fract, char *str);
void			ft_choose_fract(t_fract *fract);
void			ft_pre_mandelbrot(t_fract *fract);
void			ft_mandelbrot(t_mand *fract);
t_mand			*ft_mand_init(t_mand *mand, t_fract *fract);
t_fract			*ft_free_fract(t_fract *fract);
int				ft_mand_event(int keycode, t_mand *mand);
int				ft_mandel_mouse(int btn, int x, int y, t_mand *mand);
void			ft_zoom_mode(t_mand *mand);
void			ft_free_color_tab(t_mand *mand);

#endif
