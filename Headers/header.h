/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:00:13 by aperraul          #+#    #+#             */
/*   Updated: 2016/03/30 17:20:36 by aperraul         ###   ########.fr       */
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

typedef struct	s_jul
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
	float		cursor_x;
	float		cursor_y;
	t_pt		pmin;
	t_pt		pmax;
	t_pt		index;
}				t_jul;

void			ft_choose_fract(char *title);
void			ft_pre_mandelbrot(char *title);
void			ft_pre_julia(char *title);
void			ft_mandelbrot(t_mand *mand);
void			ft_julia(t_jul *jul);
t_mand			*ft_mand_init(t_mand *mand, t_mlx *mlx);
t_jul			*ft_jul_init(t_jul *jul, t_mlx *mlx);
int				ft_mand_event(int keycode, t_mand *mand);
int				ft_jul_event(int keycode, t_jul *jul);
int				ft_mandel_mouse(int btn, int x, int y, t_mand *mand);
int				ft_jul_mouse(int x, int y , t_jul *jul);
void			ft_mand_zoom_mode(t_mand *mand);
void			ft_jul_zoom_mode(t_jul *jul);
void			ft_free_mand(t_mand *mand);
void			ft_free_jul(t_jul *jul);

#endif
