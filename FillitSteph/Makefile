# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/22 15:14:22 by sgirard           #+#    #+#              #
#    Updated: 2020/10/23 10:29:04 by sgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c annexe.c correct_file.c find_the_square.c\
	   ft_go_backtracking.c ft_map.c map_functions.c\
	   stock_tetris.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	gcc $(CFLAGS) $(SRCS) -L./libft -lft -o $(NAME)

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all