# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 17:37:29 by ade-fran          #+#    #+#              #
#    Updated: 2023/12/27 17:37:32 by ade-fran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

LIB = libft/libft.a

SOURCES = main.c \
		srcs/instructions/push.c \
		srcs/instructions/rev_rotate.c \
		srcs/instructions/rotate.c \
		srcs/instructions/swap.c \
		srcs/parsing/make_list.c \
		srcs/parsing/split_args.c \
		srcs/sorting/costs_a.c \
		srcs/sorting/costs_b.c \
		srcs/sorting/sort_to_a.c \
		srcs/sorting/sort_to_b.c \
		srcs/sorting/sort_utils.c \
		srcs/sorting/sort.c \
		srcs/sorting/target.c \

SOURCES_BONUS = main_bonus.c \
		srcs/instructions/push.c \
		srcs/instructions/rev_rotate.c \
		srcs/instructions/rotate.c \
		srcs/instructions/swap.c \
		srcs/parsing/make_list.c \
		srcs/parsing/split_args.c \
		srcs/sorting/costs_a.c \
		srcs/sorting/costs_b.c \
		srcs/sorting/sort_to_a.c \
		srcs/sorting/sort_to_b.c \
		srcs/sorting/sort_utils.c \
		srcs/sorting/sort.c \
		srcs/sorting/target.c \

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I $(INCLD_DIR)

INCLD_DIR = ./

CC = cc

all: lib $(NAME)

lib :
	make -C libft/

$(LIB) : lib

$(NAME): $(OBJECTS) $(LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB) -o $(NAME)

bonus : $(NAME_BONUS) 

$(NAME_BONUS) : $(OBJECTS_BONUS) $(LIB)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIB) -o $(NAME_BONUS)

clean:
	make fclean -C libft/
	rm -f $(LIB) $(OBJECTS) $(OBJECTS_BONUS)

fclean:
	make fclean -C libft/
	rm -f $(NAME) $(NAME_BONUS) $(LIB) $(OBJECTS) $(OBJECTS_BONUS)

re: fclean all

.PHONY: fclean clean all re
