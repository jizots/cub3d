/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_human.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:28:57 by hotph             #+#    #+#             */
/*   Updated: 2023/10/09 16:29:06 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_raycast_to_human_vector(t_meta *meta)
{
	t_ray		verti;
	t_ray		horiz;
	t_point2df	wall;
	double		adding_radian;

	adding_radian = 0;
	while (adding_radian <= meta->human.fov)
	{
		init_ray(&verti, &horiz, meta, &adding_radian);
		wall = get_point2d_wall(&verti, &horiz, meta, verti.vector);
		my_mlx_draw_bresenham_line(&(meta->mlx), meta->human.point,
			(t_point2df){wall.x, wall.y}, RAY_COLOR);
		adding_radian += meta->human.fov / 2;
	}
}

void	cub3d_draw_human(t_meta *meta)
{
	draw_raycast_to_human_vector(meta);
	my_mlx_draw_circle(&(meta->mlx),
		meta->human.point, HUMAN_RADIUS, meta->human.color);
}
