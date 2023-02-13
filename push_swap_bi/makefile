# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 19:11:09 by jaewpark          #+#    #+#              #
#    Updated: 2023/02/13 13:32:21 by heejunki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEB = checker

CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs/
BNS_DIR = ./bonus/
OBJ_DIR = ./obj/
OBJB_DIR = ./objb/
INC_DIR = ./includes/

SRC_FILES = push_swap.c \
			linked.c \
			utils_a.c \
			utils_b.c \
			parsing.c \
			lis.c \
			sort_a.c \
			sort_b.c \
			sort_utils.c \
			init.c

BNS_FILES = checker.c \
			get_next_line_util.c \
			get_next_line.c \
			operation_a.c \
			operation_b.c \
			init.c \
			linked.c \
			parsing.c

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJB_FILES = $(BNS_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJB = $(addprefix $(OBJB_DIR), $(OBJB_FILES))
BNS = $(addprefix $(BNS_DIR), $(BNS_FILES))

ifdef WITH_BONUS
		TARGET = objb $(NAMEB)
	else
		TARGET = obj $(NAME)
endif

.PHONY	:	all
all	: $(TARGET)

.PHONY	:	bonus
bonus	:
		make WITH_BONUS=1 all

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

objb:
	@mkdir -p $(OBJB_DIR)
$(OBJB_DIR)%.o:$(BNS_DIR)%.c
	$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(NAMEB): $(OBJB)
	$(CC) $(FLAGS) -o $(NAMEB) $(OBJB)

.PHONY	:	clean
clean	:
	rm -Rf $(OBJ_DIR) $(OBJB_DIR)

.PHONY	:	fclean
fclean: clean
	$(RM) $(NAME) $(NAMEB)

.PHONY	:	re
re: fclean all
