# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 16:17:47 by heejunki              #+#    #+#              #
#    Updated: 2023/05/04 23:30:27 by heejunki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

CC				=	cc

CFLAG			=	-Wall -Wextra -Werror

LIBFT_DIR		=	libft/
LIBFT			=	libft.a
LIBFT_C			=	-L$(LIBFT_DIR) -lft

INCLUDES		=	includes/

SRCS_M			=	srcs/pipex.c						\
					srcs/child.c						\
					srcs/parent.c						\
					srcs/utils.c						\
					srcs/path.c							\
					srcs/other.c						\
									
SRCS_B			=	srcs/pipex_bonus.c					\
					srcs/child_bonus.c					\
					srcs/parent_bonus.c					\
					srcs/utils_bonus.c					\
					srcs/hd_bonus.c						\
					srcs/path_bonus.c					\
					srcs/other_bonus.c					\
					gnl/get_next_line.c					\
					gnl/get_next_line_utils.c			\
					
OBJS_M			=	$(SRCS_M:.c=.o)
OBJS_B			=	$(SRCS_B:.c=.o)

%.o		: %.c
			$(CC) $(CFLAG) -I$(INCLUDES) -c $< -o $@

BONUS_MODE = $(findstring $(MAKECMDGOALS),bonus)
ifeq ($(BONUS_MODE), )
    OBJS = $(OBJS_M)
else
    OBJS = $(OBJS_B)
endif

.PHONY	: all
all		: $(NAME)

.PHONY	: bonus
bonus	: $(NAME)

$(NAME)	: $(OBJS)
			@$(MAKE) -C $(LIBFT_DIR) all
			@$(CC) $(CFLAG) -I$(INCLUDES) $(OBJS) $(LIBFT_C) -o $(NAME)

.PHONY	: clean
clean	:
			@$(MAKE) -C $(LIBFT_DIR) clean
			@rm -rf $(OBJS_M) 
			@rm -rf $(OBJS_B)

.PHONY	: fclean
fclean	: clean
			@$(MAKE) -C $(LIBFT_DIR) fclean
			@rm -rf $(NAME)

.PHONY	: re
re		:
			@make fclean
			@make all