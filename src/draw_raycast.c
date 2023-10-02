/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:09:39 by hotph             #+#    #+#             */
/*   Updated: 2023/10/02 18:23:16 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	next_vertical_intersec(
	t_point2df start, t_ray *verti, double vector, int tile_size)
{
	if (verti->flag == 1)
	{
		if (is_up_direction(vector))
			tile_size *= -1;
		verti->intersec.y = start.y + tile_size;
		verti->intersec.x = start.x + (tile_size / tan(vector));
		return ;
	}
	if (almost_equal_double(vector, 0.0) || almost_equal_double(vector, M_PI))
	{
		verti->intersec = start;
		return ;
	}
	if (is_up_direction(vector))
		verti->intersec.y = floor(start.y / tile_size) * tile_size - 1;
	else
		verti->intersec.y = floor(start.y / tile_size) * tile_size + tile_size;
	verti->intersec.x = start.x
		+ ((verti->intersec.y - start.y) / tan(vector));
}

void	next_horizontal_intersec(
	t_point2df start, t_ray *horiz, double vector, int tile_size)
{
	if (horiz->flag == 1)
	{
		if (!is_right_direction(vector))
			tile_size *= -1;
		horiz->intersec.x = start.x + tile_size;
		horiz->intersec.y = start.y + (tile_size * tan(vector));
		return ;
	}
	if (almost_equal_double(vector, M_PI / 2)
		|| almost_equal_double(vector, M_PI * 3 / 2))
	{
		horiz->intersec = start;
		return ;
	}
	if (is_right_direction(vector))
		horiz->intersec.x = floor(start.x / tile_size) * tile_size + tile_size;
	else
		horiz->intersec.x = floor(start.x / tile_size) * tile_size - 1;
	horiz->intersec.y = start.y
		+ ((horiz->intersec.x - start.x) * tan(vector));
}

bool	is_wall(t_point2df point, t_mlx *mlx)
{
	unsigned int	color;

	if (point.x < 0 || point.x >= SCREEN_WIDTH
		|| point.y < 0 || point.y >= SCREEN_HEIGHT)
		return (true);
	color = *((unsigned int *)(mlx->addr + ((int)point.y * mlx->line_length
					+ (int)point.x * (mlx->bits_per_pixel / 8))));
	if (color == WALL_COLOR && color != HUMAN_COLOR && color != RAY_COLOR)
		return (true);
	return (false);
}

t_point2df	get_point2d_wall(
	t_ray *verti, t_ray *horiz, t_meta *meta, double vector_ray)
{
	t_point2df	current;

	current = meta->human.point;
	while (is_wall(current, &(meta->mlx)) == false)
	{
		if ((is_up_direction(vector_ray)
				&& verti->intersec.y > horiz->intersec.y)
			|| (!is_up_direction(vector_ray)
				&& verti->intersec.y < horiz->intersec.y))
		{
			update_current_point(&current, &(verti->intersec),
				&(verti->flag), &(horiz->flag));
			next_vertical_intersec(
				current, verti, vector_ray, meta->tile_size);
		}
		else
		{
			update_current_point(&current, &(horiz->intersec),
				&(horiz->flag), &(verti->flag));
			next_horizontal_intersec(
				current, horiz, vector_ray, meta->tile_size);
		}
	}
	return (current);
}

void	draw_raycast_to_human_vector(t_meta *meta)
{
	t_ray		verti;
	t_ray		horiz;
	t_point2df	wall;
	double		adding_degree;

	adding_degree = 0;
	while (adding_degree <= meta->human.fov)
	{
		init_ray(&verti, &horiz, meta, &adding_degree);
		wall = get_point2d_wall(&verti, &horiz, meta, verti.vector);
		my_mlx_draw_bresenham_line(&(meta->mlx), meta->human.point,
			(t_point2df){wall.x, wall.y}, RAY_COLOR);
		adding_degree += meta->human.fov / 2;
	}
}
