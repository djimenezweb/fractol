NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I./minilibx
SRC			= *.c
OBJS		= $(SRC:.c=.o)
DEPS		= minilibx/libmlx.a minilibx/libmlx_Linux.a

all :	$(DEPS) $(NAME)

minilibx/libmlx.a :
	$(MAKE) -C minilibx

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DEPS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) -C minilibx clean

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C minilibx fclean

re : fclean all

.PHONY : all bonus clean fclean re