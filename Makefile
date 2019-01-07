# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guroux <guroux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 12:36:35 by guroux            #+#    #+#              #
#    Updated: 2019/01/07 13:40:36 by guroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC  = ./main.c

OBJECT = $(SRC:.c=.o)

HEADERS = 	./includes	\
			./get_next_line/get_next_line.h


LIB = ./libft

CC = gcc

FLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
WHITE = \033[1;37m
BLUE = \033[1;34m
RED = \033[0;31m
YELLOW = \033[1;33m

OKGREEN = $(YELLOW)\t===== $(GREEN)[OK]$(WHITE)
KORED = $(YELLOW)\t===== $(RED)[error]$(WHITE)

$(NAME): libft
	@$(CC) $(FLAGS) -I $(LIB)/includes -c $(SRC) -I $(HEADERS) && echo "- $(BLUE)Objects Creation$(OKGREEN)" || (echo "- $(BLUE)Objects Creation$(KORED)" && false)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECT) && echo "- $(BLUE)Compilation$(OKGREEN)" || (echo "- $(BLUE)Compilation$(KORED)" && false)


libft:
	$(MAKE) -C $(LIB)


all: $(NAME)

clean:
	@rm -rf $(OBJECT)
	@echo "- $(BLUE)Deleted objects$(OKGREEN)"

fclean: clean
	@rm -rf $(NAME)
	@echo "- $(BLUE)Deleted exe$(OKGREEN)"

re: fclean all
