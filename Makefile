# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 21:45:12 by takiapo           #+#    #+#              #
#    Updated: 2017/11/29 11:25:11 by takiapo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	philo
SRC				= 	src/main.c\
					src/rendu.c\
					src/math.c\
					src/initialize.c


LIBFT			=	libft/libft.a
MINILIBXFT		=	libxft/libxft.a

OBJDIR			=	obj
SRCDIR			=	src
LIBFTDIR		=	libft
MINILIBXFTDIR	=	libxft


LIB				=	-Llibft/ -lft -L/opt/X11/lib -lX11 -lGL -lGLU
CFLAGS			=	-Wall -Wextra -Werror


OBJECTS			=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INCLUDE			=	-I includes -I /opt/X11/include -I libft/includes

$(LIBFT):
	@make -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJECTS)
	@$(CC)  $(CFLAGS) $(INCLUDE) $(LIB) -o $(NAME) $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p obj	
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

makerelibft:
	make -C $(LIBFTDIR) re

all : $(NAME)

clean :
	@rm -rf $(OBJECTS)

fclean : clean
	@rm -rf $(NAME)

re: makerelibft fclean all

