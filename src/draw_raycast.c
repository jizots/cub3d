/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:09:39 by hotph             #+#    #+#             */
/*   Updated: 2023/10/19 19:13:59 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static bool	almost_equal_0_180(
	t_point2df start, t_ray *change, double vector, int tile_size)
{
	if (almost_equal_double(vector, 0.0))
	{
		change->intersec = (t_point2df){start.x + tile_size, start.y};
		return (true);
	}
	else if (almost_equal_double(vector, M_PI))
	{
		change->intersec = (t_point2df){start.x - tile_size, start.y};
		return (true);
	}
	return (false);
}

static bool	almost_equal_90_270(
	t_point2df start, t_ray *change, double vector, int tile_size)
{
	if (almost_equal_double(vector, M_PI / 2))
	{
		change->intersec = (t_point2df){start.x, start.y + tile_size};
		return (true);
	}
	else if (almost_equal_double(vector, M_PI * 3 / 2))
	{
		change->intersec = (t_point2df){start.x, start.y - tile_size};
		return (true);
	}
	return (false);
}

void	next_vertical_intersec(
	t_point2df start, t_ray *verti, double vector, int tile_size)
{
	if (almost_equal_0_180(start, verti, vector, tile_size))
		return ;
	if (verti->flag == 1)
	{
		if (is_up_direction(vector))
			tile_size *= -1;
		verti->intersec.y = start.y + tile_size;
		verti->intersec.x = start.x + (tile_size / tan(vector));
		return ;
	}
	if (is_up_direction(vector))
		verti->intersec.y = floor(start.y / tile_size) * tile_size - 0.0001;
	else
		verti->intersec.y = floor(start.y / tile_size) * tile_size + tile_size;
	verti->intersec.x = start.x
		+ ((verti->intersec.y - start.y) / tan(vector));
}

void	next_horizontal_intersec(
	t_point2df start, t_ray *horiz, double vector, int tile_size)
{
	if (almost_equal_90_270(start, horiz, vector, tile_size))
		return ;
	if (horiz->flag == 1)
	{
		if (!is_right_direction(vector))
			tile_size *= -1;
		horiz->intersec.x = start.x + tile_size;
		horiz->intersec.y = start.y + (tile_size * tan(vector));
		return ;
	}
	if (is_right_direction(vector))
		horiz->intersec.x = floor(start.x / tile_size) * tile_size + tile_size;
	else
		horiz->intersec.x = floor(start.x / tile_size) * tile_size - 0.0001;
	horiz->intersec.y = start.y
		+ ((horiz->intersec.x - start.x) * tan(vector));
}

t_point2df	get_point2d_wall(
	t_ray *verti, t_ray *horiz, t_meta *meta, double vector_ray)
{
	t_point2df	current;

	current = meta->human.point;
	while (is_wall((t_point2di){current.x, current.y}, &(meta->mlx)) == false)
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
