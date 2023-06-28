# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 16:17:47 by heejunki          #+#    #+#              #
#    Updated: 2023/06/27 14:36:04 by heejunki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	philo

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=thread -g

INCLUDES	=	includes/
SRC			=	srcs/create.c 		\
				srcs/utils.c 		\
				srcs/time.c			\
				srcs/init.c			\
				srcs/main.c			\
				srcs/die.c
				
OBJS		= 	$(SRC:.c=.o)

%.o		: %.c
			$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

.PHONY	: all
all		: $(NAME)
$(NAME)	: $(OBJS) $(INCLUDES)
			$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJS) -o $(NAME)

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