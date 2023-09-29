/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:32:53 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/28 18:04:17 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_map(t_meta *meta)
{
	if (meta->height_map > meta->width_map)
		meta->map_scale = MAP_HEIGHT / meta->height_map;
	else
		meta->map_scale = MAP_WIDTH / meta->width_map;
	meta->human.position.x = meta->human.position.x * meta->map_scale;
	meta->human.position.y = meta->human.position.y * meta->map_scale;
}

void	draw_human(t_meta *meta)
{
	my_mlx_draw_circle(&(meta->mlx),
		meta->human.position, HUMAN_RADIUS, meta->human.color);
	my_mlx_draw_vector(&(meta->mlx),
		meta->human.position, meta->human.vector, meta->human.color);
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
					(t_point2d){j * meta->map_scale, i * meta->map_scale},
					meta->map_scale, WALL_COLOR);
			}
			j++;
		}
		i++;
	}
}

void	draw_map(t_meta *meta)
{
	draw_wall_of_map(meta);
}

void	cub3d_draw_map(t_meta *meta)
{
	init_map(meta);
	draw_map(meta);
	draw_human(meta);
}
