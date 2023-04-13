/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:45:38 by mravera           #+#    #+#             */
/*   Updated: 2023/04/13 02:29:15 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_data		data;
	int			i;

	i = 0;
	data = (t_data){0};
	if (argc > 1)
		parsing(argc, argv, &data);
	else
		printf("Error\nNeed a .cub configuration file as argument\n");
	printf("\n\n--------------DATAS--------------\n");
	printf("no = %s\n", data.no);
	printf("so = %s\n", data.so);
	printf("ea = %s\n", data.ea);
	printf("we = %s\n", data.we);
	printf("c = %s\n", data.c);
	printf("f = %s\n\n", data.f);
	printf("player x = %lf\n       y = %lf\n", data.player_x, data.player_y);
	printf("     dir = %d\n", data.p_dir);
	t_get_dist(data.p_dir, &data);
	while (data.map && data.map[i])
		printf("%s\n", data.map[i ++]);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "SUUU!");
	mlx_hook(data.win, 2, 1L << 0, cb_keypress, &data);
	mlx_hook(data.win, 17, 1L << 2, cb_close, &data);
	mlx_hook(data.win, 6, 1L << 6, cb_mouse, &data);
	mlx_hook(data.win, 4, 1L << 2, cb_mousepress, &data);
	mlx_loop_hook(data.mlx, next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}

/*
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
	if (abs(r.dx) > abs(r.dy))
		r.steps = abs(r.dx);
	else
		r.steps = abs(r.dy);
	r.xinc = r.dx / (float) r.steps;
	r.yinc = r.dy / (float) r.steps;
	r.x = x0;
	r.y = y0;
	while (i <= r.steps)
	{
		mlx->img.data[(int) round(r.x) * WIN_WIDTH +
		(int) round(r.y)] = 0x19BF37;
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


//int	main(void)
//{
//	t_mlx	mlx;
//
//	mlx.map = ft_calloc(sizeof (char *), 5);
//	mlx.map[0] = ft_strdup("11111");
//	mlx.map[1] = ft_strdup("10101");
//	mlx.map[2] = ft_strdup("10201");
//	mlx.map[3] = ft_strdup("11111");
//
//	init_window(&mlx);
//	init_minimap(&mlx, mlx.map);
//	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
//	mlx_loop(mlx.mlx_ptr);
//
//	free(mlx.map[0]);
//	free(mlx.map[1]);
//	free(mlx.map[2]);
//	free(mlx.map[3]);
//	free(mlx.map);
//	return (0);
//}

void	display_map(t_mlx *mlx)
{
	int x = 0;
	while (mlx->map[x])
	{
		printf("%s\n", mlx->map[x]);
		x++;
	}
}

void	drawLine(int x, int start, int end, int color, t_mlx *mlx)
{
	while(start < end)
	{
		mlx->img.data[start * WIN_WIDTH + x] = color;
		start++;
	}
}

void	raycasting(t_mlx *mlx)
{
	double posX = 3.5;
	double posY = 2.5;
	double dirX = -1;
	double dirY = 0;
	double planX = 0;
	double planY = 0.66;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int	stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int x;

	x = 0;
	while(x < WIN_WIDTH)
	{
		cameraX = 2 * x / (double) WIN_WIDTH - 1;
		rayDirX = dirX + planX * cameraX;
		rayDirY = dirY + planY * cameraX;
		mapX = (int)posX;
		mapY = (int)posY;
		deltaDistX = sqrt(1 + (dirY * dirY) / (dirX * dirX));
		deltaDistY = sqrt(1 + (dirX * dirX) / (dirY * dirY));
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		hit = 0;
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (mlx->map[mapX][mapY] != '0')
				hit = 1;
		}
		printf("hit at : %d / %d\n", mapX, mapY);
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		lineHeight = abs((int)(WALL_HEIGHT / perpWallDist));
		drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;
		drawLine(x, drawStart, drawEnd, 0xBF610E, mlx);
		x++;
	}
}

void	freemap(t_mlx *mlx)
{
	int x = 0;
	while (mlx->map[x])
	{
		free(mlx->map[x]);
		x++;
	}
	free(mlx->map);
}

int main(void)
{
	t_mlx mlx;

	mlx.map = ft_calloc(sizeof (char *), 6);
	mlx.map[0] = ft_strdup("1111111");
	mlx.map[1] = ft_strdup("1000101");
	mlx.map[2] = ft_strdup("1100011");
	mlx.map[3] = ft_strdup("1010001");
	mlx.map[4] = ft_strdup("1111111");

	init_window(&mlx);
	raycasting(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);

	freemap(&mlx);
	return (0);
}
*/

/*
	printf("0, 0 = %d\n", t_whatis(0, 0, &data));
	printf("1, 0 = %d\n", t_whatis(1, 0, &data));
	printf("1, 1 = %d\n", t_whatis(1, 1, &data));
	printf("1, 2 = %d\n", t_whatis(1, 2, &data));
	printf("1, 3 = %d\n", t_whatis(1, 3, &data));
	printf("1, 4 = %d\n", t_whatis(1, 4, &data));
	printf("1, 5 = %d\n", t_whatis(1, 5, &data));
	printf("1, 6 = %d\n", t_whatis(1, 6, &data));
	printf("1, 7 = %d\n", t_whatis(1, 7, &data));
	printf("1, 8 = %d\n", t_whatis(1, 8, &data));
	printf("1, 9 = %d\n", t_whatis(1, 9, &data));
	printf("2, 0 = %d\n", t_whatis(2, 0, &data));
	printf("2, 1 = %d\n", t_whatis(2, 1, &data));
	printf("2, 2 = %d\n", t_whatis(2, 2, &data));
	printf("2, 3 = %d\n", t_whatis(2, 3, &data));
	printf("2, 4 = %d\n", t_whatis(2, 4, &data));
	printf("2, 5 = %d\n", t_whatis(2, 5, &data));
	printf("2, 6 = %d\n", t_whatis(2, 6, &data));
	printf("2, 7 = %d\n", t_whatis(2, 7, &data));
	printf("2, 8 = %d\n", t_whatis(2, 8, &data));
	printf("2, 9 = %d\n", t_whatis(2, 9, &data));
	printf("3, 0 = %d\n", t_whatis(3, 0, &data));
	printf("3, 1 = %d\n", t_whatis(3, 1, &data));
	printf("3, 2 = %d\n", t_whatis(3, 2, &data));
	printf("3, 3 = %d\n", t_whatis(3, 3, &data));
	printf("3, 4 = %d\n", t_whatis(3, 4, &data));
	printf("3, 5 = %d\n", t_whatis(3, 5, &data));
	printf("3, 6 = %d\n", t_whatis(3, 6, &data));
	printf("3, 7 = %d\n", t_whatis(3, 7, &data));
	printf("3, 8 = %d\n", t_whatis(3, 8, &data));
	printf("3, 9 = %d\n", t_whatis(3, 9, &data));
	printf("4, 0 = %d\n", t_whatis(4, 0, &data));
	printf("4, 1 = %d\n", t_whatis(4, 1, &data));
	printf("4, 2 = %d\n", t_whatis(4, 2, &data));
	printf("4, 3 = %d\n", t_whatis(4, 3, &data));
	printf("4, 4 = %d\n", t_whatis(4, 4, &data));
	printf("4, 5 = %d\n", t_whatis(4, 5, &data));
	printf("4, 6 = %d\n", t_whatis(4, 6, &data));
	printf("4, 7 = %d\n", t_whatis(4, 7, &data));
	printf("4, 8 = %d\n", t_whatis(4, 8, &data));
	printf("4, 9 = %d\n", t_whatis(4, 9, &data));
	printf("5, 0 = %d\n", t_whatis(5, 0, &data));
	printf("5, 1 = %d\n", t_whatis(5, 1, &data));
	printf("5, 2 = %d\n", t_whatis(5, 2, &data));
	printf("5, 3 = %d\n", t_whatis(5, 3, &data));
	printf("5, 4 = %d\n", t_whatis(5, 4, &data));
	printf("5, 5 = %d\n", t_whatis(5, 5, &data));
	printf("5, 6 = %d\n", t_whatis(5, 6, &data));
	printf("5, 7 = %d\n", t_whatis(5, 7, &data));
	printf("5, 8 = %d\n", t_whatis(5, 8, &data));
	printf("5, 9 = %d\n", t_whatis(5, 9, &data));
	printf("6, 0 = %d\n", t_whatis(6, 0, &data));
	printf("6, 1 = %d\n", t_whatis(6, 1, &data));
	printf("6, 2 = %d\n", t_whatis(6, 2, &data));
	printf("6, 3 = %d\n", t_whatis(6, 3, &data));
	printf("6, 4 = %d\n", t_whatis(6, 4, &data));
	printf("6, 5 = %d\n", t_whatis(6, 5, &data));
	printf("6, 6 = %d\n", t_whatis(6, 6, &data));
	printf("6, 7 = %d\n", t_whatis(6, 7, &data));
	printf("6, 8 = %d\n", t_whatis(6, 8, &data));
	printf("6, 9 = %d\n", t_whatis(6, 9, &data));
	printf("7, 0 = %d\n", t_whatis(7, 0, &data));
	printf("7, 1 = %d\n", t_whatis(7, 1, &data));
	printf("7, 2 = %d\n", t_whatis(7, 2, &data));
	printf("7, 3 = %d\n", t_whatis(7, 3, &data));
	printf("7, 4 = %d\n", t_whatis(7, 4, &data));
	printf("7, 5 = %d\n", t_whatis(7, 5, &data));
	printf("7, 6 = %d\n", t_whatis(7, 6, &data));
	printf("7, 7 = %d\n", t_whatis(7, 7, &data));
	printf("7, 8 = %d\n", t_whatis(7, 8, &data));
	printf("7, 9 = %d\n", t_whatis(7, 9, &data));
	printf("8, 0 = %d\n", t_whatis(8, 0, &data));
	printf("8, 1 = %d\n", t_whatis(8, 1, &data));
	printf("8, 2 = %d\n", t_whatis(8, 2, &data));
	printf("8, 3 = %d\n", t_whatis(8, 3, &data));
	printf("8, 4 = %d\n", t_whatis(8, 4, &data));
	printf("8, 5 = %d\n", t_whatis(8, 5, &data));
	printf("8, 6 = %d\n", t_whatis(8, 6, &data));
	printf("8, 7 = %d\n", t_whatis(8, 7, &data));
	printf("8, 8 = %d\n", t_whatis(8, 8, &data));
	printf("8, 9 = %d\n", t_whatis(8, 9, &data));
	printf("9, 0 = %d\n", t_whatis(9, 0, &data));
	printf("9, 1 = %d\n", t_whatis(9, 1, &data));
	printf("9, 2 = %d\n", t_whatis(9, 2, &data));
	printf("9, 3 = %d\n", t_whatis(9, 3, &data));
	printf("9, 4 = %d\n", t_whatis(9, 4, &data));
	printf("9, 5 = %d\n", t_whatis(9, 5, &data));
	printf("9, 6 = %d\n", t_whatis(9, 6, &data));
	printf("9, 7 = %d\n", t_whatis(9, 7, &data));
	printf("9, 8 = %d\n", t_whatis(9, 8, &data));
	printf("9, 9 = %d\n", t_whatis(9, 9, &data));
*/
