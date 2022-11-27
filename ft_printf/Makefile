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

NAME	= 	libftprintf.a

CC		= 	cc
CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar
ARFLAGS	= 	-crus

INC		= 	ft_printf.h
SRCS	= 	ft_description_check.c \
			ft_itoa.c \
			ft_printf.c \
			ft_putbase_ap.c \
			ft_putchr_ap.c \
			ft_putdigit_ap.c \
			ft_puthex_ap.c \
			ft_putptr_ap.c \
			ft_putstr_ap.c \
			ft_putuhex_ap.c \
			ft_putunsdigit_ap.c \
			ft_strlen.c 

OBJS	=	$(SRCS:.c=.o)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

.PHONY	:	all
all		:	$(NAME)

$(NAME)	:	$(OBJS)													
			$(AR) $(ARFLAGS) $@ $< $?

.PHONY	:	clean
clean	:
			rm -f $(OBJS)

.PHONY	:	fclean
fclean	:	clean
			rm -f $(NAME)

.PHONY	:	re
re		:
			make fclean
			make all