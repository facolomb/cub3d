/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clean_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:28:29 by mravera           #+#    #+#             */
/*   Updated: 2023/02/23 19:51:31 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

char	**get_clean_buf(int fd)
{
	char	*treuse;
	char	**res;

	treuse = get_next_line(fd);
	while (treuse[0] == '\n')
	{
		free(treuse);
		treuse = get_next_line(fd);
	}
	treuse = rm_lastbsn(treuse);
	res = ft_split(treuse, ' ');
	free(treuse);
	return (res);
}

char	*rm_lastbsn(char *str)
{
	int		i;
	char	*treuse;

	if (str == NULL)
		return (str);
	i = ft_strlen(str);
	if (i > 0 && str[i - 1] == '\n')
	{
		treuse = (char *)malloc(i * sizeof (char));
		ft_strlcpy(treuse, str, i);
		free(str);
		return (treuse);
	}
	return (str);
}
