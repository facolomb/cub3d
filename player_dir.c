/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:52:05 by mravera           #+#    #+#             */
/*   Updated: 2023/04/05 14:54:40 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	p_dirup(t_player *p)
{
	p->dir += DIR_STEP;
	if (p->dir >= 360)
		p->dir = 0;
	return (1);
}

int	p_dirdown(t_player *p)
{
	p->dir -= DIR_STEP;
	if (p->dir < 0)
		p->dir = 360 - DIR_STEP;
	return (1);
}
