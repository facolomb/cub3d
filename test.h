
#ifndef TEST_H   
#define TEST_H
#include "mlx/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080
#define WALL_HEIGHT 64


typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	char	**map;
	t_img 	img;
}	t_mlx;

typedef struct s_rayon
{
	int	length;
	int start_point[2];
	int end_point[2];
}	t_rayon;

typedef struct s_draw_line
{
	int dx;
	int dy;
	int steps;
	float xinc;
	float yinc;
	float x;
	float y;
}	t_draw_line;

#endif
