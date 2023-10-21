/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycast_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:19:32 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/19 19:14:06 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

char	which_direction(const t_ray *verti, const double radian)
{
	if (is_up_direction(radian))
	{
		if (verti->flag == 1)
			return ('N');
		else if (is_right_direction(radian))
			return ('E');
		else
			return ('W');
	}
	else
	{
		if (verti->flag == 1)
			return ('S');
		else if (is_right_direction(radian))
			return ('E');
		else
			return ('W');
	}
}

void	update_current_point(
	t_point2df *current, t_point2df *next, int *flag_up, int *flag_down)
{
	*current = *next;
	*flag_up = 1;
	*flag_down = 0;
}

void	init_ray(
	t_ray *verti, t_ray *horiz, t_meta *meta, double *add_radian)
{
	t_point2df	start;

	start = meta->human.point;
	verti->flag = 0;
	horiz->flag = 0;
	verti->vector = meta->human.vector - (meta->human.fov / 2) + *add_radian;
	horiz->vector = verti->vector;
	set_radian_within_2pi(&(verti->vector));
	next_vertical_intersec(start, verti, verti->vector, meta->tile_size);
	next_horizontal_intersec(start, horiz, horiz->vector, meta->tile_size);
}

bool	is_wall(t_point2di point, t_mlx *mlx)
{
	unsigned int	color;

	if (point.x < 0 || point.x >= SCREEN_WIDTH
		|| point.y < 0 || point.y >= SCREEN_HEIGHT)
		return (true);
	color = *((unsigned int *)(mlx->addr + (point.y * mlx->line_length
					+ point.x * (mlx->bits_per_pixel / 8))));
	if (color == WALL_COLOR)
		return (true);
	return (false);
}
