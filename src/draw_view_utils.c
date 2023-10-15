/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:10:01 by hotph             #+#    #+#             */
/*   Updated: 2023/10/15 15:18:57 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

bool	is_map(size_t x, size_t y, t_meta *meta)
{
	if (x < (meta->tile_size * meta->width_map)
		&& y < (meta->tile_size * meta->height_map))
		return (true);
	return (false);
}

double	get_tex_x(
	t_point2df *wall, const char dire, const int tile_size)
{
	double	integer;

	if (dire == 'N' || dire == 'S')
		return (modf((wall->x / tile_size), &integer));
	else
		return (modf((wall->y / tile_size), &integer));
}

int	get_color_from_texture(t_tex tex, int x, int y)
{
	int		color;

	color = *(int *)(tex.addr + (y * tex.line_length
				+ x * (tex.bpp / 8)));
	return (color);
}
