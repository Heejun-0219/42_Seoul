CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op
SRCS = ./do_op.c ./operation.c ./main.c

all : $(NAME)

$(NAME) : $(SRCS)
	@$(CC) $(CFLAGS) -o $@ $^ -I ./ft.h

clean :
	@rm -f $(NAME)

fclean : clean


re : fclean all


.PHONY : all fclean re clean
