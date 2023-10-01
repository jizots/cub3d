/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:09:39 by hotph             #+#    #+#             */
/*   Updated: 2023/10/01 18:56:46 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	next_vertical_intersec(
	t_point2di start, t_ray *verti, double vector, int tile_size)
{
	if (verti->flag == 1)
	{
		if (is_up_direction(vector))
			tile_size *= -1;
		verti->intersec.y = start.y + tile_size;
		verti->intersec.x = start.x + tile_size / tan(vector);
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
	verti->intersec.x = start.x + (verti->intersec.y - start.y) / tan(vector);
}

void	next_horizontal_intersec(
	t_point2di start, t_ray *horiz, double vector, int tile_size)
{
	if (horiz->flag == 1)
	{
		if (!is_right_direction(vector))
			tile_size *= -1;
		horiz->intersec.x = start.x + tile_size;
		horiz->intersec.y = start.y + tile_size * tan(vector);
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
	horiz->intersec.y = start.y + (horiz->intersec.x - start.x) * tan(vector);
}

bool	is_wall(t_point2di point, t_mlx *mlx)
{
	unsigned int	color;

	if (point.x < 0 || point.x >= SCREEN_WIDTH
		|| point.y < 0 || point.y >= SCREEN_HEIGHT)
		return (true);
	color = *((unsigned int *)(mlx->addr + (point.y * mlx->line_length
					+ point.x * (mlx->bits_per_pixel / 8))));
	if (color == WALL_COLOR && color != HUMAN_COLOR && color != RAY_COLOR)
		return (true);
	return (false);
}

void	update_current_point(
	t_point2di *current, t_point2di *next, int *flag_up, int *flag_down)
{
	*current = *next;
	*flag_up = 1;
	*flag_down = 0;
}

t_point2di	get_point2d_wall(
	t_ray *verti, t_ray *horiz, t_meta *meta, double vector_ray)
{
	t_point2di	current;

	current = (t_point2di){(int)meta->human.point.x, (int)meta->human.point.y};
	while (is_wall(current, &(meta->mlx)) == false)
	{
		if ((is_up_direction(vector_ray)
				&& verti->intersec.y > horiz->intersec.y)
			|| (!is_up_direction(vector_ray)
				&& verti->intersec.y < horiz->intersec.y))
		{
			update_current_point(&current, &(verti->intersec),
				&(verti->flag), &(horiz->flag));
puts("current is verti");
printf("current: %d, %d\n", current.x, current.y);
			next_vertical_intersec(
				current, verti, vector_ray, meta->tile_size);
		}
		else
		{
			update_current_point(&current, &(horiz->intersec),
				&(horiz->flag), &(verti->flag));
puts("current is horiz");
printf("current: %d, %d\n", current.x, current.y);
			next_horizontal_intersec(
				current, horiz, vector_ray, meta->tile_size);
		}
	}
	return (current);
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
puts("-------------------");
printf("start: %d, %d\n", start.x, start.y);
printf("verti: %d, %d\n", verti->intersec.x, verti->intersec.y);
printf("horiz: %d, %d\n", horiz->intersec.x, horiz->intersec.y);
}

void	draw_raycast_to_human_vector(t_meta *meta)
{
	t_ray		verti;
	t_ray		horiz;
	t_point2di	wall;
	double		adding_degree;
puts("-------------------");

	adding_degree = 0;
	while (adding_degree <= meta->human.fov)
	{
		init_ray(&verti, &horiz, meta, &adding_degree);
		wall = get_point2d_wall(&verti, &horiz, meta, verti.vector);
printf("wall: %d, %d\n", wall.x, wall.y);
		my_mlx_draw_bresenham_line(&(meta->mlx), meta->human.point,
			(t_point2df){wall.x, wall.y}, RAY_COLOR);
		adding_degree += meta->human.fov / 2;
	}
}
