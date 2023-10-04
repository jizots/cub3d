/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_human_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:49:46 by hotph             #+#    #+#             */
/*   Updated: 2023/10/03 14:48:36 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
