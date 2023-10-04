/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:40:25 by hotph             #+#    #+#             */
/*   Updated: 2023/10/04 13:55:36 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static t_collision	convert_collision_data(
	const t_point2df *start, const t_point2df *wall,
	const t_ray *verti)
{
	t_collision	colli;

	colli.dis = distance_of_point(*start, *wall);
	colli.dire = which_direction(verti, verti->vector);
	return (colli);
}

static t_collision	get_fov_wall_data(t_meta *meta, const int col)
{
	t_ray		verti;
	t_ray		horiz;
	t_point2df	wall;
	double		adding_radian;
	t_collision colli;

	adding_radian = (meta->human.fov / SCREEN_WIDTH) * col;
	init_ray(&verti, &horiz, meta, &adding_radian);
	wall = get_point2d_wall(&verti, &horiz, meta, verti.vector);
	colli = convert_collision_data(&(meta->human.point), &wall, &verti);
	colli.col = col;
	return (colli);
}

void	draw_view(t_meta *meta)
{
	int			col;
	t_collision	colli;

	col = 0;
	while (col < SCREEN_WIDTH)
	{
		colli = get_fov_wall_data(meta, col);
		col++;
	}
	(void)colli;
}