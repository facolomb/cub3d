/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:57:40 by mravera           #+#    #+#             */
/*   Updated: 2023/02/23 22:42:44 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

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

int	is_map(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] == ' ')
		i++;
	if (str[i++] == '1')
		n ++;
	while (str[i] == ' ' || str[i] == '1')
		i ++;
	if (n == 0)
		return (0);
	if (str[i] == '\0')
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
