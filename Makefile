NAME = test

SRC = test.c \
		parsing.c \
		cub_gnl.c \
		cub_gnl_utils.c \
		check_args.c \
		videur.c \
		cub_utils.c \
		get_clean_buf.c \
		parsing_utils.c \
		map_utils.c \
		get_map.c \
		check_map.c \
		is_map_closed.c \
		cub_flood.c \
		player_move.c \
		player_dir.c \
		t_raymain.c \
		wall_distance.c \
		get_nsew_dist.c \
		mlx_draw.c \
		mlx_hooks.c \

MLX_PATH = ./mlx

MLX = ./mlx/libmlx.a

LIBFT_PATH = ./libft

LIBFT = ./libft/libft.a

CFLAGS = -g -Wall -Werror -Wextra #-fsanitize=address

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