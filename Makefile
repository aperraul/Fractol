# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperraul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 16:10:30 by aperraul          #+#    #+#              #
#    Updated: 2016/05/25 12:45:10 by aperraul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = ./sources/main.c \
	  ./sources/choose_fract.c \
	  ./sources/ft_pre_mandelbrot.c \
	  ./sources/ft_pre_julia.c \
	  ./sources/ft_pre_newton.c \
	  ./sources/ft_mandelbrot.c \
	  ./sources/ft_julia.c \
	  ./sources/ft_newton.c \
	  ./sources/mand_event.c\
	  ./sources/julia_event.c \
	  ./sources/newt_event.c \
	  ./sources/frac_tool.c \
	  ./sources/ft_free_frac.c \

OBJS = ./main.o \
	   ./choose_fract.o \
	   ./ft_pre_mandelbrot.o \
	   ./ft_pre_newton.o \
	   ./ft_pre_julia.o \
	   ./ft_mandelbrot.o \
	   ./ft_julia.o \
	   ./ft_newton.o \
	   ./mand_event.o \
	   ./julia_event.o \
	   ./newt_event.o \
	   ./frac_tool.o \
	   ./ft_free_frac.o \

DRAW = ./Libdraw/draw.a

LIBFT = ./libft/libft.a

LIBMLX = ./libmlx/libmlx.a

LMLX = -lmlx

FRAMEWORK = $(LMLX) -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(DRAW) $(OBJS)
	$(CC) $(FLAGS) $(FRAMEWORK) $(OBJS) $(LIBFT) $(LIBMLX) $(DRAW) -o $(NAME)

$(OBJS): $(LIBFT) $(LIBMLX) $(DRAW)
	$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
	make -C ./libft/

$(LIBMLX):
	make -C ./libmlx/

$(DRAW):
	make -C ./Libdraw/

clean:
	$(RM) $(OBJS)
	make clean -C ./libft/
	make clean -C ./libmlx/
	make clean -C ./Libdraw/

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(LIBMLX) $(DRAW)

re: fclean all
