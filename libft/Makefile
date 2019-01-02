# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guroux <guroux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 15:00:56 by guroux            #+#    #+#              #
#    Updated: 2018/12/21 20:39:49 by guroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC  =  ./ft_memalloc.c 	\
		./ft_bzero.c		\
		./ft_strlen.c		\
		./ft_toupper.c		\
		./ft_tolower.c		\
		./ft_isdigit.c		\
		./ft_isalpha.c		\
		./ft_isalnum.c		\
		./ft_isascii.c		\
		./ft_isprint.c		\
		./ft_strcmp.c		\
		./ft_strncmp.c		\
		./ft_putnbr.c		\
		./ft_putchar.c		\
		./ft_putstr.c		\
		./ft_putendl.c		\
		./ft_memdel.c		\
		./ft_strnew.c		\
		./ft_strdel.c		\
		./ft_strclr.c		\
		./ft_striter.c		\
		./ft_striteri.c		\
		./ft_strmap.c		\
		./ft_strmapi.c		\
		./ft_strequ.c		\
		./ft_strnequ.c		\
		./ft_strsub.c		\
		./ft_strjoin.c		\
		./ft_strsplit.c		\
		./ft_strtrim.c		\
		./ft_putchar_fd.c	\
		./ft_putstr_fd.c	\
		./ft_putendl_fd.c	\
		./ft_putnbr_fd.c	\
		./ft_memset.c		\
		./ft_memcpy.c		\
		./ft_memccpy.c		\
		./ft_memmove.c		\
		./ft_memchr.c		\
		./ft_memcmp.c		\
		./ft_strdup.c		\
		./ft_strcpy.c		\
		./ft_strncpy.c		\
		./ft_strcat.c		\
		./ft_strncat.c		\
		./ft_strlcat.c		\
		./ft_strchr.c		\
		./ft_strrchr.c		\
		./ft_strstr.c		\
		./ft_strnstr.c		\
		./ft_atoi.c			\
		./ft_itoa.c			\
		./ft_strrev.c		\
		./ft_lstnew.c		\
		./ft_lstdelone.c	\
		./ft_lstdel.c		\
		./ft_lstadd.c		\
		./ft_lstiter.c		\
		./ft_lstmap.c		\
		./ft_sort_table.c	\
		./ft_count.c		\
		./ft_abs.c			\
		./ft_dtaballoc.c

OBJECT = $(SRC:.c=.o)

HEADERS = ./includes

CC = gcc

FLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
WHITE = \033[1;37m
BLUE = \033[1;34m
RED = \033[0;31m
YELLOW = \033[1;33m

OKGREEN = $(YELLOW)\t===== $(GREEN)[OK]$(WHITE)
KORED = $(YELLOW)\t===== $(RED)[error]$(WHITE)

$(NAME): $(SRC) $(HEADERS) Makefile
	@$(CC) -c $(FLAGS) -I$(HEADERS) $(SRC) && echo "- $(BLUE)Compilation$(OKGREEN)" || (echo "- $(BLUE)Compile$(KORED)" && false)
	@ar rc $(NAME) $(OBJECT) && echo "- $(BLUE)Create lib$(OKGREEN)" || (echo "- $(BLUE)Create lib$(KORED)" && false)
	@ranlib $(NAME) && echo "- $(BLUE)Index lib$(OKGREEN)" || (echo "- $(BLUE)Index lib$(KORED)" && false)

all: $(NAME)

clean:
	@rm -rf $(OBJECT)
	@echo "- $(BLUE)Delete object$(OKGREEN)"

fclean: clean
	@rm -rf $(NAME)
	@echo "- $(BLUE)Delete lib$(OKGREEN)"

count:
	@printf "$(GREEN)"
	@git config remote.origin.url
	@echo $(SRC) | wc -w | xargs printf "$(YELLOW)\n- Makefile .c \t==== \t%d\n"
	@cat $(HEADERS)/libft.h | grep "ft_" | wc -l | xargs printf "$(YELLOW)- Libft.h .c \t==== \t%d\n"
	@find -E . -type f -regex "./.?.+\.c" | wc -w | xargs printf "$(YELLOW)- File(s) .c \t==== \t%d\n"
	@find -E . -type f -regex "./.?.+\.o" | wc -w | xargs printf "$(YELLOW)- File(s) .o \t==== \t%d\n"
	@find -E . -type f -regex "./.?.+\.a" | wc -w | xargs printf "$(YELLOW)- Libft.a .a \t==== \t%d\n"

re: fclean all