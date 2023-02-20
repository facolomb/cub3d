NAME = test

SRC = test.c \
		parsing.c \
		cub_gnl.c \
		cub_gnl_utils.c

MLX_PATH = ./mlx

MLX = ./mlx/libmlx.a

LIBFT_PATH = ./libft

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C mlx
		make -C libft
		gcc $(CFLAGS) -I $(MLX_PATH) $(OBJ) $(LIBFT) -L $(MLX_PATH) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean:
		make -C mlx clean
		make -C libft clean
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re