/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:59:39 by mravera           #+#    #+#             */
/*   Updated: 2023/04/02 15:33:12 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

void	freetab(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ;
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
	if (data->map != NULL)
		freetab(data->map);
	return (0);
}

void	printab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
	return ;
}
