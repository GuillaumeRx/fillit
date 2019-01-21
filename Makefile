# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guroux <guroux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 12:36:35 by guroux            #+#    #+#              #
#    Updated: 2019/01/21 18:19:10 by guroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re

NAME = fillit

SRC  =	./main.c		\
		./board.c 		\
		./fillit.c		\
		./others.c		\
		./list.c		\
		./check_error.c \
		./valid_or_invalid.c	\
		./convert_board_into_block_list.c	\
		./get_next_line.c					\

OBJECT = $(SRC:.c=.o)

HEADERS = 	./get_next_line.h	\
			./fillit.h			\

LIB = libft

CC = gcc

FLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
WHITE = \033[1;37m
BLUE = \033[1;34m
RED = \033[0;31m
YELLOW = \033[1;33m

OKGREEN = $(YELLOW)\t===== $(GREEN)[OK]$(WHITE)
KORED = $(YELLOW)\t===== $(RED)[error]$(WHITE)

$(NAME): $(LIB)
	@$(CC) $(FLAGS) -I libft/includes -c $(SRC) -I $(HEADERS) && echo "- $(BLUE)Objects Creation$(OKGREEN)" || (echo "- $(BLUE)Objects Creation$(KORED)" && false)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECT) -L libft/ -lft && echo "- $(BLUE)Compilation$(OKGREEN)" || (echo "- $(BLUE)Compilation$(KORED)" && false)


$(LIB):
	@$(MAKE) -C $(LIB)


all: $(NAME)

clean:
	@rm -rf $(OBJECT)
	@echo "- $(BLUE)Deleted objects$(OKGREEN)"
	@$(MAKE) clean -C $(LIB)

fclean: clean
	@rm -rf $(NAME)
	@echo "- $(BLUE)Deleted exe$(OKGREEN)"
	@$(MAKE) fclean -C $(LIB)

re: fclean all
