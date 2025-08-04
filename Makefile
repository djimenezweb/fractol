NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
SRC			= fractol.c
OBJS		= $(SRC:.c=.o)

all :	$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re