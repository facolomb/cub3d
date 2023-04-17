NAME = cub3D

SRC = main.c \
		cb_close.c \
		cb_colors.c \
		check_args.c \
		check_map.c \
		cub_flood.c \
		cub_gnl.c \
		cub_gnl_utils.c \
		cub_utils.c \
		get_clean_buf.c \
		get_map.c \
		get_nsew_border.c \
		get_nsew_dist.c \
		get_nsew_next.c \
		get_textures.c \
		is_map_closed.c \
		map_utils.c \
		mlx_draw.c \
		mlx_hooks.c \
		next_frame.c \
		parsing.c \
		parsing_utils.c \
		player_dir.c \
		player_move.c \
		ray_utils.c \
		t_raymain.c \
		videur.c \

MLX_PATH = ./mlx

MLX = ./mlx/libmlx.a

LIBFT_PATH = ./libft

LIBFT = ./libft/libft.a

CFLAGS = -ofast -Wall -Werror -Wextra 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C mlx
		make -C libft
		gcc $(CFLAGS) -I $(MLX_PATH) $(OBJ) $(LIBFT) -L $(MLX_PATH) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

%.o : %.c
		gcc $(CFLAGS) -c $< -o $@

clean:
		make -C mlx clean
		make -C libft clean
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re