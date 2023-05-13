# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 18:21:27 by heejunki          #+#    #+#              #
#    Updated: 2023/04/07 18:25:56 by heejunki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror -Iheaders/

SOURCE  = 	game_logic/controls.c\
			game_logic/errors.c\
			game_logic/errors_two.c\
			game_logic/map.c\
			game_logic/moves.c\
			game_logic/so_long.c
GETNEXTLINE	= 	get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c
LIBRARY	= -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX 	= minilibx/

OBJS	= $(SOURCE:.c=.o)
%.o		: %.c
			$(CC) $(CFLAGS) -c $< -o $@

.PHONY	: all
all		: $(NAME) 
$(NAME)	: $(SOURCE) $(GETNEXTLINE) $(OBJS)
			@$(MAKE) -C $(MINILIBX)
			@$(CC) $(CFLAGS) -o $@ $(SOURCE) $(GETNEXTLINE) $(LIBRARY)

.PHONY	: clean
clean	:
			@$(MAKE) -C $(MINILIBX) clean
			@rm -rf *.o
			@rm -rf *.gch
			@rm -rf *.dSYM

.PHONY	: fclean
fclean	: clean
			@rm -rf $(NAME)

.PHONY	: re
re		: 
			@make fclean 
			@make all
