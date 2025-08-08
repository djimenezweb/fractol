NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
SRC			= events.c fractol.c mandelbrot.c print-utils.c
OBJS		= $(SRC:.c=.o)

# Minilibx
MLX_PATH	= minilibx-linux
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)/$(MLX_NAME)
MLX_LINK	= -lXext -lX11 -lm
#MLX_LINK	= -lXext -lX11 -lm -lz
MLX_COMP	= $(MLX) -I./$(MLX_PATH) $(MLX_LINK)

# Libft
LIBFT_PATH	= libft
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)/$(LIBFT_NAME)
LIBFT_COMP	= $(LIBFT) -I./$(LIBFT_PATH)/

all : $(MLX) $(LIBFT) $(NAME)

$(MLX) :
	@echo "=== Making MiniLibX ==="
	@$(MAKE) -sC $(MLX_PATH)

$(LIBFT) :
	@echo "=== Making Libft ==="
	@$(MAKE) -sC $(LIBFT_PATH)

$(NAME) : $(OBJS)
	@echo "=== Compiling ==="
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_COMP) $(MLX_COMP) -o $(NAME)

%.o : %.c
	@echo "=== Creating object files ==="
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean :
	@echo "=== Removing .o files ==="
	@rm -f $(OBJS)
	@echo "=== Removing Minilibx .o files ==="
	@$(MAKE) clean -sC $(MLX_PATH)
	@echo "=== Removing Libft .o files ==="
	@$(MAKE) clean -sC $(LIBFT_PATH)

fclean : clean
	@echo "=== Removing fractol executable ==="
	@rm -f $(NAME)
	@echo "=== Removing Libft ==="
	@rm -f $(LIBFT)

re : fclean all
	@echo "=== Rebuilding ==="

run : all
	@$(MAKE) clean
	./$(NAME)

check : all
	valgrind ./$(NAME)

.PHONY : all clean fclean re run check