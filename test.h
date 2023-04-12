/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:21:51 by mravera           #+#    #+#             */
/*   Updated: 2023/04/12 16:53:28 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "parsing.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

//# define WIN_WIDTH 1920
/*
# define WIN_WIDTH 600
# define WIN_HEIGHT 600
# define WALL_HEIGHT 64
# define DIR_STEP 1
# define X_STEP 0.1
# define Y_STEP 0.1
*/

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
	t_img	img;
}	t_mlx;

typedef struct s_rayon
{
	int	length;
	int	start_point[2];
	int	end_point[2];
}	t_rayon;

typedef struct s_draw_line
{
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
	float	x;
	float	y;
}	t_draw_line;

#endif
