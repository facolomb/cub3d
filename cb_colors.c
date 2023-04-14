/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:01:17 by mravera           #+#    #+#             */
/*   Updated: 2023/04/14 04:29:34 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	str_color(char *s)
{
	char	**buf;
	int		r;
	int		g;
	int		b;

	if (!s)
		return (create_trgb(0, 127, 255, 0));
	buf = ft_split(s, ',');
	r = ft_atoi(buf[0]);
	g = ft_atoi(buf[1]);
	b = ft_atoi(buf[2]);
	freetab(buf);
	return (create_trgb(0, r, g, b));
}
