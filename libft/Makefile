# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:34:04 by mbinder           #+#    #+#              #
#    Updated: 2017/11/29 11:27:51 by takiapo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SDIR = ./srcs/

IDIR = ./includes/

ODIR = ./objs/

OFILE = objs

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_toupper.c ft_tolower.c \
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
	  ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_inttohexstr.c ft_exit.c ft_isspace.c ft_strjoinf.c ft_freetab2d.c \
		ft_strlen2d.c ft_error.c

OBJ = $(patsubst %.c, $(ODIR)/%.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror -O3 -funsigned-char -g

all: $(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(ODIR)/%.o:$(addprefix $(SDIR)/, %.c)
	@mkdir -p $(ODIR)
	gcc $(CFLAGS) -o $@ -c $^ -I$(IDIR)

clean:
	/bin/rm -rf $(OFILE)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
