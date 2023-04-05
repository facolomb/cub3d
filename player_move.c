/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:42:40 by mravera           #+#    #+#             */
/*   Updated: 2023/04/05 14:52:54 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	p_xup(t_player *p)
{
	p->pos_x += X_STEP;
	return (1);
}

int	p_yup(t_player *p)
{
	p->pos_y += Y_STEP;
	return (1);
}

int	p_xdown(t_player *p)
{
	p->pos_x -= X_STEP;
	return (1);
}

int	p_ydown(t_player *p)
{
	p->pos_y -= Y_STEP;
	return (1);
}
