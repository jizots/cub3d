/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:09:39 by hotph             #+#    #+#             */
/*   Updated: 2023/09/30 14:50:15 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_next_intersection_vertical(
	t_point2d start, t_ray *vertical, double vector, double tile_size)
{
	if (vertical->flag == 1)
	{
		if (IS_UP_DIRECTION(vector))
			tile_size *= -1;
		vertical->intersection.y = start.y + tile_size;
		vertical->intersection.x = start.x + tile_size / vertical->tan_ray;
		return ;
	}
	if (almost_equal_double(vector, 0.0) || almost_equal_double(vector, M_PI))
	{
		vertical->intersection = start;
		return ;
	}
	if (IS_UP_DIRECTION(vector))
		vertical->intersection.y
			= floor(start.y / tile_size) * tile_size - 1;
	else
		vertical->intersection.y
			= floor(start.y / tile_size) * tile_size + tile_size;
	vertical->intersection.x
		= start.x + (vertical->intersection.y - start.y) / vertical->tan_ray;
}

void	find_next_intersection_horizontal(
	t_point2d start, t_ray *horizontal, double vector, double tile_size)
{
	if (horizontal->flag == 1)
	{
		if (!IS_RIGHT_DIRECTION(vector))
			tile_size *= -1;
		horizontal->intersection.x = start.x + tile_size;
		horizontal->intersection.y = start.y + tile_size * horizontal->tan_ray;
		return ;
	}
	if (almost_equal_double(vector, M_PI / 2)
		|| almost_equal_double(vector, M_PI * 3 / 2))
	{
		horizontal->intersection = start;
		return ;
	}
	if (IS_RIGHT_DIRECTION(vector))
		horizontal->intersection.x
			= floor(start.x / tile_size) * tile_size + tile_size;
	else
		horizontal->intersection.x
			= floor(start.x / tile_size) * tile_size - 1;
	horizontal->intersection.y
		= start.y
		+ (horizontal->intersection.x - start.x) * horizontal->tan_ray;
}

bool	is_wall(t_point2d point, t_meta *meta)
{
	unsigned int	color;

	if (point.x < 0 || point.x >= SCREEN_WIDTH
		|| point.y < 0 || point.y >= SCREEN_HEIGHT)
		return (true);
	color = *((unsigned int *)(meta->mlx.addr
				+ ((int)point.y * meta->mlx.line_length
					+ (int)point.x * (meta->mlx.bits_per_pixel / 8))));
	if (color == WALL_COLOR && color != HUMAN_COLOR && color != RAY_COLOR)
		return (true);
	return (false);
}

void	update_current_point(
	t_point2d *current, t_point2d *next, int *flag_up, int *flag_down)
{
	*current = *next;
	*flag_up = 1;
	*flag_down = 0;
}

t_point2d	get_point2d_wall(t_ray *vertical, t_ray *horizontal, t_meta *meta)
{
	t_point2d	current;

	current = meta->human.point;
	while (is_wall(current, meta) == false)
	{
		if ((IS_UP_DIRECTION(meta->human.vector)
				&& vertical->intersection.y > horizontal->intersection.y)
			|| (!IS_UP_DIRECTION(meta->human.vector)
				&& vertical->intersection.y < horizontal->intersection.y))
		{
			update_current_point(&current, &(vertical->intersection),
				&(vertical->flag), &(horizontal->flag));
			find_next_intersection_vertical(
				current, vertical, meta->human.vector, meta->tile_size);
		}
		else
		{
			update_current_point(&current, &(horizontal->intersection),
				&(horizontal->flag), &(vertical->flag));
			find_next_intersection_horizontal(
				current, horizontal, meta->human.vector, meta->tile_size);
		}
	}
	return (current);
}

void	draw_raycast_to_human_vector(t_meta *meta)
{
	t_point2d	start;
	t_ray		vertical;
	t_ray		horizontal;
	t_point2d	wall;

	vertical.flag = 0;
	horizontal.flag = 0;
	start = meta->human.point;
	vertical.tan_ray = tan(meta->human.vector);
	horizontal.tan_ray = vertical.tan_ray;
	find_next_intersection_vertical(
		start, &vertical, meta->human.vector, meta->tile_size);
	find_next_intersection_horizontal(
		start, &horizontal, meta->human.vector, meta->tile_size);
	wall = get_point2d_wall(&vertical, &horizontal, meta);
	my_mlx_draw_bresenham_line(
		&(meta->mlx), meta->human.point, wall, RAY_COLOR);
}
