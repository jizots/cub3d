/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_gradation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:30:58 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/08 11:39:18 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

void	get_color_interval(uint32_t from, uint32_t to,
					double interval, double *color_interval)
{
	unsigned char	c_from[4];
	unsigned char	c_to[4];
	int				i;

	get_trgb_color(from, c_from);
	get_trgb_color(to, c_to);
	i = 0;
	while (i < 4)
	{
		color_interval[i] = (double)(c_to[i] - c_from[i]) / (double)interval;
		i++;
	}
}

int	get_color_gradation(uint32_t from, double *color_interval, int repeat)
{
	unsigned char	c_from[4];
	int				color_create;

	get_trgb_color(from, c_from);
	color_create
		= create_trgb_color
		((unsigned char)(c_from[0] + (char)(color_interval[0] * repeat)),
			(unsigned char)(c_from[1] + (char)(color_interval[1] * repeat)),
			(unsigned char)(c_from[2] + (char)(color_interval[2] * repeat)),
			(unsigned char)(c_from[3] + (char)(color_interval[3] * repeat)));
	return (color_create);
}
