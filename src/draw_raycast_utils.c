/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycast_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:19:32 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/01 19:26:31 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_current_point(
	t_point2di *current, t_point2di *next, int *flag_up, int *flag_down)
{
	*current = *next;
	*flag_up = 1;
	*flag_down = 0;
}

void	init_ray(
	t_ray *verti, t_ray *horiz, t_meta *meta, double *adding_degree)
{
	t_point2di	start;

	start = (t_point2di){(int)meta->human.point.x, (int)meta->human.point.y};
	verti->flag = 0;
	horiz->flag = 0;
	verti->vector = meta->human.vector - (meta->human.fov / 2) + *adding_degree;
	horiz->vector = verti->vector;
	set_radian_within_2pi(&(verti->vector));
	next_vertical_intersec(start, verti, verti->vector, (int)meta->tile_size);
	next_horizontal_intersec(start, horiz, horiz->vector, (int)meta->tile_size);
}
