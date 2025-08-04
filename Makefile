NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
SRC			= fractol.c
OBJS		= $(SRC:.c=.o)

all : $(MINILIBX) $(NAME)

$(MINILIBX) :
	if [ ! -d "minilibx-linux"]; then git clone https://github.com/42paris/minilibx-linux.git; fi
	$(MAKE) -C minilibx

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -Lminilibx-linux -l:libmlx_Linux.a -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re