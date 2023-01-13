# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 06:34:00 by heejunki          #+#    #+#              #
#    Updated: 2022/11/27 06:34:01 by heejunki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap

CC		= 	cc
CFLAGS	= 	-Wall -Wextra -Werror

INC		= 	push_swap_src/push_swap.h
SRCS	= 	push_swap_src/push_swap.c\
			push_swap_src/overflow_check.c\
			push_swap_src/param_check.c\
			push_swap_src/param_utilts.c

.PHONY	:	all
all		:	$(NAME)
$(NAME)	:	
			@$(MAKE) -C libft/ re bonus
			$(CC) $(CFLAGS) -o $@ $(SRCS) -L libft/ -lft -I $(INC)

.PHONY	:	clean
clean	:
			@$(MAKE) -C libft/ clean

.PHONY	:	fclean
fclean	:	clean
			rm -f $(NAME)
			@$(MAKE) -C libft/ fclean

.PHONY	:	re
re		:
			make fclean
			make all