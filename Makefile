#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/01/14 02:38:28 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell1

SRCC = 	main.c				signal.c			error.c				\
		fill_env.c			builtin.c								\
		builtin/exit.c		builtin/env.c		 builtin/setenv.c	\
		builtin/unsetenv.c	builtin/cd.c

SRCO = zboub

FLAG = -Wall -Werror -Wextra

.PHONY: all lib brute clean fclean re

all: $(NAME)

$(NAME):
	@rm -f $(NAME)
	@gcc $(FLAG) $(SRCC) -o $(NAME) -I ./libft/inc/ -I ./ libft/libft.a

lib:
	@cd libft; make re; cd ..

brute: lib fclean all

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(NAME)

re: fclean all
