/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:57:40 by mravera           #+#    #+#             */
/*   Updated: 2023/04/14 23:03:21 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_nsewkey(char *str)
{
	if (!ft_strncmp(str, "N", 2) || !ft_strncmp(str, "NO", 3)
		|| !ft_strncmp(str, "E", 2) || !ft_strncmp(str, "EA", 3)
		|| !ft_strncmp(str, "W", 2) || !ft_strncmp(str, "WE", 3)
		|| !ft_strncmp(str, "S", 2) || !ft_strncmp(str, "SO", 3))
		return (1);
	return (0);
}

int	is_fckey(char *str)
{
	if (!ft_strncmp(str, "C", 2) || !ft_strncmp(str, "F", 2))
		return (1);
	return (0);
}

int	str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == ','))
			return (0);
		else
			i++;
	}
	return (1);
}

int	alrdy_set(char **str, t_data *data)
{
	if ((!ft_strncmp(str[0], "N", 2) || !ft_strncmp(str[0], "NO", 3))
		&& data->no != 0)
		return (printf("\n[%s->%s]\nTexture already set.\n", str[0], str[1]));
	else if ((!ft_strncmp(str[0], "S", 2) || !ft_strncmp(str[0], "SO", 3))
		&& data->so != 0)
		return (printf("\n[%s->%s]\nTexture already set.\n", str[0], str[1]));
	else if ((!ft_strncmp(str[0], "E", 2) || !ft_strncmp(str[0], "EA", 3))
		&& data->ea != 0)
		return (printf("\n[%s->%s]\nTexture already set.\n", str[0], str[1]));
	else if ((!ft_strncmp(str[0], "W", 2) || !ft_strncmp(str[0], "WE", 3))
		&& data->we != 0)
		return (printf("\n[%s->%s]\nTexture already set.\n", str[0], str[1]));
	else if (!ft_strncmp(str[0], "F", 2) && data->f_color != 0)
		return (printf("\n[%s->%s]\nF color already set.\n", str[0], str[1]));
	else if (!ft_strncmp(str[0], "C", 2) && data->c_color != 0)
		return (printf("\n[%s->%s]\nC color already set.\n", str[0], str[1]));
	return (0);
}

int	set_texture(t_imgdata *img, char *path, t_data *data)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path, &(img->img_width),
			&(img->img_height));
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->l_length),
			&(img->endian));
	return (1);
}
