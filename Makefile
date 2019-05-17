# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlegros <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 18:55:39 by vlegros           #+#    #+#              #
#    Updated: 2019/01/25 17:48:15 by vlegros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fillit
RESOURCES = *.c
OBJ = $(RESOURCES:.c=.o)
ADD_SRC = ./src/
ADD_INC = ./includes/
ADD_LIB_H = ./libft/
ADD_LIB = ./libft/libft.a

all: $(NAME)
$(NAME):
	@make  -C ./libft all
	@$(COMPILER) -c $(FLAGS) -I $(ADD_INC)  $(ADD_SRC)$(RESOURCES)
	@$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ) $(ADD_LIB)
	@mv $(OBJ) $(ADD_SRC)
clean:
	@rm -f $(ADD_SRC)$(OBJ)
	@make  -C ./libft clean
fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean
re: fclean all
