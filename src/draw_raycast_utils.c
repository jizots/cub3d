/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycast_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:19:32 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/03 14:48:54 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_current_point(
	t_point2df *current, t_point2df *next, int *flag_up, int *flag_down)
{
	*current = *next;
	*flag_up = 1;
	*flag_down = 0;
}

void	init_ray(
	t_ray *verti, t_ray *horiz, t_meta *meta, double *adding_radian)
{
	t_point2df	start;

	start = meta->human.point;
	verti->flag = 0;
	horiz->flag = 0;
	verti->vector = meta->human.vector - (meta->human.fov / 2) + *adding_radian;
	horiz->vector = verti->vector;
	set_radian_within_2pi(&(verti->vector));
	next_vertical_intersec(start, verti, verti->vector, meta->tile_size);
	next_horizontal_intersec(start, horiz, horiz->vector, meta->tile_size);
}
