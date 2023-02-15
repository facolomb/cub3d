/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:04:08 by mravera           #+#    #+#             */
/*   Updated: 2023/02/15 15:58:37 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	parsing(int argc, char **argv)
{
	check_file(argc, argv);
	return (0);
}

int	check_file(int argc, char **argv)
{
	int		i;

	i = 0;
	argv++;
	while (*argv)
	{
		if (is_cub(*argv))
			i++;
		argv++;
	}
	if (i == 1 && argc == 2)
		printf(".cub found\n");
	if (i >= 1 && argc > 2)
		printf("using first valid .cub argument...\n");
	if (i <= 0)
		printf("no valid .cub found, aborting...\n");
	return (0);
}

int	is_cub(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
		return (0);
	if (str[i - 1] == 'b' && str[i - 2] == 'u'
		&& str[i - 3] == 'c' && str[i - 4] == '.')
		return (1);
	else
		return (0);
}
