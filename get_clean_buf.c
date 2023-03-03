/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clean_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:28:29 by mravera           #+#    #+#             */
/*   Updated: 2023/03/03 19:10:04 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

char	**get_clean_buf(char *str)
{
	char	**treuse;
	char	*l;

	l = rm_lastbsn(str);
	treuse = ft_split(l, ' ');
	printf("%p BBBBBBBBB\n", treuse);
	free(l);
	return (treuse);
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
		str = 0;
		return (treuse);
	}
	return (str);
}
