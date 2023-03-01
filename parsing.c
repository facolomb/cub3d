/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:04:08 by mravera           #+#    #+#             */
/*   Updated: 2023/03/01 01:39:21 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	parsing(int argc, char **argv)
{
	t_data	data;
	int		fd;

	data = (t_data){0};
	fd = check_cub(argc, argv);
	parse(fd, &data);
	check_close(fd);
	return (0);
}

int	parse(int fd, t_data *data)
{
	char	**buf;
	int		i;

	i = 0;
	buf = get_clean_buf(fd);
	while (buf[0] != NULL && !is_map(buf[0]))
	{
		videur(buf, data);
		freetab(buf);
		buf = get_clean_buf(fd);
		i++;
	}
	freetab(buf);
	printf("no = %s\n", data->no);
	printf("so = %s\n", data->so);
	printf("ea = %s\n", data->ea);
	printf("we = %s\n", data->we);
	printf("c = %s\n", data->c);
	printf("f = %s\n", data->f);
	free_data(data);
	return (0);
}

int	free_data(t_data *data)
{
	if (data->no != NULL)
		free(data->no);
	if (data->so != NULL)
		free(data->so);
	if (data->ea != NULL)
		free(data->ea);
	if (data->we != NULL)
		free(data->we);
	if (data->c != NULL)
		free(data->c);
	if (data->f != NULL)
		free(data->f);
	return (0);
}
