# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 16:17:47 by heejunki          #+#    #+#              #
#    Updated: 2023/06/27 00:50:07 by heejunki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	philo_bonus

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

INCLUDES	=	includes/

SRC			=	srcs/assign.c 		\
				srcs/utils.c 		\
				srcs/utils_1.c		\
				srcs/init.c			\
				srcs/main.c			\
				srcs/implementation.c
				
OBJS		= 	$(SRC:.c=.o)

%.o		: %.c
			$(CC) $(CFLAG) -I$(INCLUDES) -c $< -o $@

.PHONY	: all
all		: $(NAME)
$(NAME)	: $(OBJS)
			@$(CC) $(CFLAG) -I$(INCLUDES) $(OBJS) -o $(NAME)

.PHONY	: clean
clean	:
			@rm -rf $(OBJS) 

.PHONY	: fclean
fclean	: clean
			@rm -rf $(NAME)

.PHONY	: re
re		:
			@make fclean
			@make all