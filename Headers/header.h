/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:00:13 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/01 15:45:14 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include "../Libdraw/libdraw.h"
# include "../libmlx/X.h"

# define WIN_X 1000
# define WIN_Y 750
# define THEZOOM 1.5
# define ITERATOR 1.12

typedef struct	s_frac
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
	double		cursor_x;
	double		cursor_y;
	int			nmax;
	t_pt		pos;
	t_pt		cursor;
	t_pt		pmin;
	t_pt		pmax;
	t_pt		index;
}				t_frac;

void			ft_choose_fract(char *title);
void			ft_pre_mandelbrot(char *title);
void			ft_pre_julia(char *title);
void			ft_mandelbrot(t_frac *frac);
void			ft_julia(t_frac *frac);
void			ft_image_init(t_frac *frac);
t_frac			*ft_mand_init(t_frac *frac, t_mlx *mlx);
t_frac			*ft_jul_init(t_frac *frac, t_mlx *mlx);
int				ft_mand_event(int keycode, t_frac *mand);
int				ft_jul_event(int keycode, t_frac *frac);
int				ft_mandel_mouse(int btn, int x, int y, t_frac *frac);
int				ft_jul_mouse(int x, int y , t_frac *frac);
void			ft_frac_zoom_mode(t_frac *frac);
void			ft_free_color_tab(t_frac *frac);
void			ft_frac_color(t_frac *fract);
void			ft_free_frac(t_frac *frac);
void			ft_incrementator(t_frac *frac, int mode);

#endif
