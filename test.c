
#include "test.h"
#include "parsing.h"

int	tablen(char **tab)
{
	int	count;

	if (!tab || !*tab)
		return (0);
	count = 0;
	while (tab[count])
		count++;
	return (count);
}

void	DDA(int x0, int y0, int x1, int y1, t_mlx *mlx)
{
	t_draw_line	r;
	int			i = 0;

	r.dx = x1 - x0;
	r.dy = y1 - y0;
	r.steps = abs(r.dx) > abs (r.dy) ? abs(r.dx) : abs(r.dy);
	r.xinc = r.dx / (float)r.steps;
	r.yinc = r.dy / (float)r.steps;
	r.x = x0;
	r.y = y0;
	while (i <= r.steps)
	{
		mlx->img.data[(int)round(r.x) * WIN_WIDTH + (int)round(r.y)] = 0x19BF37;
		r.x += r.xinc;
		r.y += r.yinc;
		i++;
	}
}

void	draw_player(t_mlx *mlx, int x, int y, int squareSize)
{
	int width;
	int height;

	width = -1;
	x = x + ((squareSize / 2) - 2);
	y = y + ((squareSize / 2) - 2);
	while (++width < 5)
	{
		height = -1;
		while (++height < 5)
			mlx->img.data[(x + width) * WIN_WIDTH + (y + height)] = 0x19BF37;
	}
	DDA(x + 2, y + 2, 0, y + 2, mlx);
	DDA(x + 2, y + 2, 0, (y + 2) + 160 , mlx);
	DDA(x + 2, y + 2, 0, (y + 2) - 160, mlx);
}

void	draw_square(t_mlx *mlx, int x, int y, int color, int size)
{
	int width;
	int height;

	width = -1;
	while (++width < size)
	{
		height = -1;
		while (++height < size)
		{
			if (height == 0 || height == (size - 1) || width == 0 || width == (size - 1))
				mlx->img.data[(x + width) * WIN_WIDTH + (y + height)] = 0xBF1919;
			else
				mlx->img.data[(x + width) * WIN_WIDTH + (y + height)] = color;
		}
	}
}

void	init_minimap(t_mlx *mlx, char **map)
{
	int					x;
	unsigned int		y;
	int 				color;
	int 				squareSize;
	int					isPlayer;

	x = -1;
	squareSize = 64;
	isPlayer = 0;
	while (++x < tablen(map))
	{
		y = -1;
		while (++y < ft_strlen(map[x]))
		{
			if (map[x][y] == '1')
				color = 0x000000;
			else
			{
				if (map[x][y] == '2')
					isPlayer = 1;
				color = 0xFFFFFF;
			}
			draw_square(mlx, x * squareSize, y * squareSize, color, squareSize);
			if (isPlayer == 1)
			{
				draw_player(mlx, x * squareSize, y * squareSize, squareSize);
				isPlayer = 0;
			}
		}
	}
}

void	init_window(t_mlx *mlx)
{
	int		count_w;
	int		count_h;

	count_w = -1;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Test");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = (int *) mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);

	while (++count_w < WIN_WIDTH)
	{
		count_h = -1;
		while (++count_h < WIN_HEIGHT)
		{
			if (count_h < WIN_HEIGHT / 2)
				mlx->img.data[count_h * WIN_WIDTH + count_w] = 0x2E4053;
			else
				mlx->img.data[count_h * WIN_WIDTH + count_w] = 0x1A5276;
		}
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	char	**map;

	parsing(argc, argv);
	map = ft_calloc(sizeof (char *), 5);
	map[0] = ft_strdup("11111");
	map[1] = ft_strdup("10101");
	map[2] = ft_strdup("10201");
	map[3] = ft_strdup("11111");

	init_window(&mlx);
	init_minimap(&mlx, map);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);

	free(map[0]);
	free(map[1]);
	free(map[2]);
	free(map[3]);
	free(map);
	return (0);
}
