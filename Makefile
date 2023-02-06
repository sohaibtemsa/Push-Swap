# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 15:30:57 by stemsama          #+#    #+#              #
#    Updated: 2023/02/05 20:39:25 by stemsama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

LIBFT			=	./libft/libft.a

CC = cc
FLAGS =  -Wall -Werror -Wextra

SRC = push.c swap.c rotate.c main1.c main2.c main3.c main4.c parsing.c push_rotate_v2.c
SRC_BONUS = bonus/bonus_tools1.c bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/tools1.c bonus/tools2.c bonus/tools3.c bonus/tools4.c

OBJECT = $(SRC:.c=.o)
OBJECT_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	@make -C ./libft all bonus
	$(CC) $(FLAGS) $(LIBFT) $(OBJECT) -o $(NAME)

bonus : $(OBJECT_BONUS)
	@make -C ./libft all bonus
	$(CC) $(FLAGS) $(LIBFT) $(OBJECT_BONUS) -o $(NAME_BONUS)

%.o:%.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@ 

clean :
	@make -C ./libft clean
	rm -f $(OBJECT) $(OBJECT_BONUS)

fclean : clean
	@make -C ./libft fclean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all 

.PHONY: clean fclean re all libft
