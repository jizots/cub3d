/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:32:53 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/01 19:26:16 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	draw_human(t_meta *meta)
{
	draw_raycast_to_human_vector(meta);
	my_mlx_draw_circle(&(meta->mlx),
		meta->human.point, HUMAN_RADIUS, meta->human.color);
}

void	draw_wall_of_map(t_meta *meta)
{
	int		i;
	int		j;

	i = 0;
	while (meta->map[i] != NULL)
	{
		j = 0;
		while (meta->map[i][j] != '\0')
		{
			if (meta->map[i][j] == '1')
			{
				my_mlx_draw_square(&(meta->mlx),
					(t_point2df){j, i},
					meta->tile_size, WALL_COLOR);
			}
			j++;
		}
		i++;
	}
}

void	cub3d_draw_map(t_meta *meta)
{
	init_map(meta);
	draw_wall_of_map(meta);
	draw_human(meta);
}
