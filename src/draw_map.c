/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:32:53 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/20 19:23:08 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	init_map(t_meta *meta)
{
	if (meta->height_map > meta->width_map)
		meta->tile_size = floor(MAP_HEIGHT / meta->height_map);
	else
		meta->tile_size = floor(MAP_WIDTH / meta->width_map);
	meta->human.point.x = meta->human.point.x * meta->tile_size
		+ meta->tile_size / 2;
	meta->human.point.y = meta->human.point.y * meta->tile_size
		+ meta->tile_size / 2;
}

void	draw_minimap(t_meta *meta)
{
	int		i;
	int		j;

	i = 0;
	while (meta->map[i] != NULL)
	{
		j = 0;
		while (meta->map[i][j] != '\0')
		{
			if (meta->map[i][j] == WALL)
				my_mlx_draw_square(&(meta->mlx),
					(t_point2df){j, i}, meta->tile_size, WALL_COLOR);
			else if (meta->map[i][j] == VISITED
				|| ft_strchr("0NWSE ", meta->map[i][j]))
				my_mlx_draw_square(&(meta->mlx),
					(t_point2df){j, i}, meta->tile_size, MAP_COLOR);
			j++;
		}
		i++;
	}
}

void	cub3d_draw_map(t_meta *meta)
{
	init_map(meta);
	draw_minimap(meta);
}
