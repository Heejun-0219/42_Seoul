NAME	= 	libft.a

CC		= 	cc
CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar
ARFLAGS	= 	-crus

INC		= 	libft.h
SRCS	= 	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c
B_SRCS	= 	ft_lstadd_back_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstmap_bonus.c\
			ft_lstnew_bonus.c\
			ft_lstsize_bonus.c

M_OBJS	=	$(SRCS:.c=.o)
B_OBJS	=	$(B_SRCS:.c=.o)

ifdef WITH_BONUS
	OBJS = $(B_OBJS) $(M_OBJS)
else
	OBJS = $(M_OBJS)
endif

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

.PHONY	:	all
all		:	
			@if [ -e "$(NAME)" ] && ar -t $(NAME) | grep -q "ft_lstnew_bonus.o"; then\
				echo "rm -f $(B_OBJS)";\
				rm -f $(B_OBJS);\
				echo "ar -d $(NAME) $(B_OBJS)";\
				ar -d $(NAME) $(B_OBJS);\
			fi
			@make $(NAME)													

.PHONY	:	bonus
bonus 	:	
			@if [ -e "$(NAME)" ] && ! ar -t $(NAME) | grep -q "ft_lstnew_bonus.o"; then\
				make $(NAME);\
				echo "$(CC) $(CFLAGS) -c $(B_SRCS) -I$(INC)";\
				$(CC) $(CFLAGS) -c $(B_SRCS) -I$(INC);\
				echo "$(AR) $(ARFLAGS) $(NAME) $(B_OBJS)";\
				$(AR) $(ARFLAGS) $(NAME) $(B_OBJS);\
			else\
				make WITH_BONUS=1 $(NAME);\
			fi

$(NAME)	:	$(OBJS)													
			$(AR) $(ARFLAGS) $(NAME) $?

.PHONY	:	clean
clean	:
			rm -f $(M_OBJS) 
			rm -f $(B_OBJS)

.PHONY	:	fclean
fclean	:	clean
			rm -f $(NAME)

.PHONY	:	re
re		:
			make fclean
			make all