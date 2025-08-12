NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
SRC_PATH	= src/
SRC			=	fractol.c \
				initialization.c \
				render.c \
				math-utils.c \
				parse-args.c \
				print-utils.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
OBJS		= $(SRCS:.c=.o)
INCLUDES	= -I./includes -I./libft -I./minilibx-linux

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
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

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
	./$(NAME) M

check : all
	valgrind ./$(NAME) M

.PHONY : all clean fclean re run check