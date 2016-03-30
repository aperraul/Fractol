# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperraul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 16:10:30 by aperraul          #+#    #+#              #
#    Updated: 2016/03/30 16:29:27 by aperraul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = ./sources/main.c \
	  ./sources/choose_fract.c \
	  ./sources/ft_pre_mandelbrot.c \
	  ./sources/ft_pre_julia.c \
	  ./sources/ft_mandelbrot.c \
	  ./sources/ft_julia.c \
	  ./sources/mand_event.c\
	  ./sources/julia_event.c \

OBJS = ./main.o \
	   ./choose_fract.o \
	   ./ft_pre_mandelbrot.o \
	   ./ft_pre_julia.o \
	   ./ft_mandelbrot.o \
	   ./ft_julia.o \
	   ./mand_event.o \
	   ./julia_event.o \

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
