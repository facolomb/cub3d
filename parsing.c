/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:04:08 by mravera           #+#    #+#             */
/*   Updated: 2023/03/04 00:17:30 by mravera          ###   ########.fr       */
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
	printf("no = %s\n", data.no);
	printf("so = %s\n", data.so);
	printf("ea = %s\n", data.ea);
	printf("we = %s\n", data.we);
	printf("c = %s\n", data.c);
	printf("f = %s\n", data.f);
	free_data(&data);
	return (0);
}

int	parse(int fd, t_data *data)
{
	char	*buf;
	char	**treuse;
	int		i;

	buf = get_next_line(fd);
	while (buf != NULL && !is_map(buf))
	{
		i = 0;
		while (buf[i] == ' ')
			i++;
		if (buf[i] && buf[i] != '\n')
		{
			treuse = get_clean_buf(buf);
			videur(treuse, data);
			freetab(treuse);
		}
		if (buf)
			free(buf);
		buf = get_next_line(fd);
	}
	if (buf)
		free(buf);
	return (0);
}
