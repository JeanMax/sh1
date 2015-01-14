#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 21:26:32 by mcanal            #+#    #+#              #
#    Updated: 2015/01/09 05:02:11 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCC = 	str/ft_strindex.c		str/ft_strrindex.c		io/get_next_line.c	\
		str/ft_atoi.c			is/ft_isalnum.c			is/ft_isalpha.c		\
		is/ft_isascii.c			is/ft_isdigit.c			is/ft_isprint.c		\
		str/ft_strcat.c			str/ft_strcmp.c			str/ft_strcpy.c		\
		str/ft_strdup.c			str/ft_strlen.c			str/ft_strncpy.c	\
		str/ft_strstr.c			str/ft_tolower.c		str/ft_toupper.c	\
		mem/ft_bzero.c			mem/ft_memccpy.c		mem/ft_memchr.c		\
		mem/ft_memcmp.c			mem/ft_memcpy.c			mem/ft_memmove.c	\
		mem/ft_memset.c			str/ft_strchr.c			str/ft_strlcat.c	\
		str/ft_strncat.c		str/ft_strncmp.c		str/ft_strnstr.c	\
		io/ft_putchar.c			io/ft_putnbr.c			io/ft_putstr.c		\
		str/ft_strdel.c			str/ft_strjoin.c		str/ft_strnew.c		\
		mem/ft_memalloc.c		io/ft_putendl.c			io/ft_putchar_fd.c	\
		str/ft_strequ.c			str/ft_strmap.c			io/ft_putnbr_fd.c	\
		mem/ft_memdel.c			io/ft_putendl_fd.c		io/ft_putstr_fd.c	\
		str/ft_striter.c		str/ft_strmapi.c		str/ft_strsub.c		\
		str/ft_strclr.c			str/ft_striteri.c		str/ft_strnequ.c	\
		is/ft_islower.c			is/ft_isupper.c			str/ft_strrchr.c	\
		is/ft_isblank.c			is/ft_iscntrl.c			is/ft_isgraph.c		\
		is/ft_ispunct.c			is/ft_isspace.c			is/ft_isxdigit.c	\
		str/ft_itoa.c			str/ft_strtrim.c		str/ft_strsplit.c	\
		lst1/ft_lstnew.c		lst1/ft_lstdelone.c		lst1/ft_lstdel.c	\
		lst1/ft_lstiter.c		lst1/ft_lstmap.c		lst1/ft_lstadd.c	\
		lst1/ft_lstaddlast.c	lst1/ft_lstisempty.c	lst1/ft_lstat.c		\
		lst1/ft_lstlast.c		lst1/ft_lstlen.c		mem/ft_realloc.c	\
		lst1/ft_lstislast.c		lst1/ft_lstinser.c		lst1/ft_lstrplc.c	\
		lst1/ft_lstfind.c		lst1/ft_lstisn.c		lst1/ft_lstdellink.c\
		lst2/ft_ladd.c			lst2/ft_laddlast.c		lst2/ft_lat.c		\
		lst2/ft_ldellink.c		lst2/ft_lfirst.c		lst2/ft_lfirst.c	\
		lst2/ft_linser.c		lst2/ft_lisempty.c		lst2/ft_lisfirst.c	\
		lst2/ft_lislast.c		lst2/ft_lisn.c			lst2/ft_liter.c		\
		lst2/ft_llast.c			lst2/ft_llen.c			lst2/ft_lrplc.c		\
		editme/ft_lnew.c		lst2/ft_lswap.c			io/get_all.c		\
		io/ft_putstr_clr.c		io/ft_putchar_clr.c		io/ft_putendl_clr.c	\
		io/ft_debugstr.c		io/ft_debugnbr.c		io/ft_putnbr_clr.c	\
		editme/ft_lfree.c		lst2/ft_lclean.c		editme/ft_lfind.c


SRCO=	ft_strindex.o	ft_strrindex.o		get_next_line.o		\
		ft_atoi.o		ft_isalnum.o		ft_isalpha.o		\
		ft_isascii.o	ft_isdigit.o		ft_isprint.o		\
		ft_strcat.o		ft_strcmp.o			ft_strcpy.o			\
		ft_strdup.o		ft_strlen.o			ft_strncpy.o		\
		ft_strstr.o		ft_tolower.o		ft_toupper.o		\
		ft_bzero.o		ft_memccpy.o		ft_memchr.o			\
		ft_memcmp.o		ft_memcpy.o			ft_memmove.o		\
		ft_memset.o		ft_strchr.o			ft_strlcat.o		\
		ft_strncat.o	ft_strncmp.o		ft_strnstr.o		\
		ft_putchar.o	ft_putnbr.o			ft_putstr.o			\
		ft_strdel.o		ft_strjoin.o		ft_strnew.o			\
		ft_memalloc.o	ft_putendl.o		ft_putchar_fd.o		\
		ft_strequ.o		ft_strmap.o			ft_putnbr_fd.o		\
		ft_memdel.o		ft_putendl_fd.o		ft_putstr_fd.o		\
		ft_striter.o	ft_strmapi.o		ft_strsub.o			\
		ft_strclr.o		ft_striteri.o		ft_strnequ.o		\
		ft_islower.o	ft_isupper.o		ft_strrchr.o		\
		ft_isblank.o	ft_iscntrl.o		ft_isgraph.o		\
		ft_ispunct.o	ft_isspace.o		ft_isxdigit.o		\
		ft_itoa.o		ft_strtrim.o		ft_strsplit.o		\
		ft_lstnew.o		ft_lstdelone.o		ft_lstdel.o			\
		ft_lstiter.o	ft_lstmap.o			ft_lstadd.o			\
		ft_lstaddlast.o	ft_lstisempty.o		ft_lstat.o			\
		ft_lstlast.o	ft_lstlen.o			ft_realloc.o		\
		ft_lstislast.o	ft_lstinser.o		ft_lstrplc.o		\
		ft_lstfind.o	ft_lstisn.o			ft_lstdellink.o		\
		ft_ladd.o		ft_laddlast.o		ft_lat.o			\
		ft_ldellink.o	ft_lfirst.o			ft_lfirst.o			\
		ft_linser.o		ft_lisempty.o		ft_lisfirst.o		\
		ft_lislast.o	ft_lisn.o			ft_liter.o			\
		ft_llast.o		ft_llen.o			ft_lrplc.o			\
		ft_lnew.o		ft_lswap.o			get_all.o			\
		ft_putstr_clr.o	ft_putchar_clr.o	ft_putendl_clr.o	\
		ft_debugstr.o	ft_debugnbr.o		ft_putnbr_clr.o		\
		ft_lfree.o		ft_lclean.o			ft_lfind.o

FLAG = -Wall -Wextra -Werror -c -I inc/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc $(FLAG) $(SRCC)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)
	@rm -f $(SRCO)

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(NAME)

re: fclean all
