/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:01:34 by mravera           #+#    #+#             */
/*   Updated: 2023/02/22 20:35:10 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	check_cub(int argc, char **argv)
{
	int		fd;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (is_cub(argv[i]))
		{
			fd = check_open(argv[i]);
			if (fd >= 0)
				return (fd);
		}
		else
			printf("[%s] is not a .cub file.\n", argv[i]);
		i++;
		if (i < argc)
			printf("\nChecking next file...\n");
		else
			printf("\nNo valid .cub found, aborting...\n");
	}
	exit(1);
}

int	check_open(char *file)
{
	int	fd;

	printf("Opening file ----> [%s]...\n", file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file ");
		return (-1);
	}
	else
		printf("File is open.\n");
	return (fd);
}

int	check_close(int fd)
{
	printf("Closing file...\n");
	if (close(fd) != 0)
	{
		perror("Error while closing the file ");
		printf("Exiting...\n");
		exit(1);
	}
	else
		printf("File closed.\n");
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
