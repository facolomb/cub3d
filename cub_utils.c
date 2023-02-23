/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:59:39 by mravera           #+#    #+#             */
/*   Updated: 2023/02/23 00:03:40 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

void	freetab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ;
}
