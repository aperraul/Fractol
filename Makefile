# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperraul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 16:10:30 by aperraul          #+#    #+#              #
#    Updated: 2016/03/18 16:35:06 by aperraul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fractol

SRC = ./sources/main.c \
	  ./sources/ft_fract_init.c \
	  ./sources/choose_fract.c \
	  ./sources/ft_mandelbrot.c \

OBJS = ./main.o \
	   ./ft_fract_init.o \
	   ./choose_fract.o \
	   ./ft_mandelbrot.o \

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
