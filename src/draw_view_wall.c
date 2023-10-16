/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:40:25 by hotph             #+#    #+#             */
/*   Updated: 2023/10/16 14:28:15 by hotph            ###   ########.fr       */
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
	t_collision	colli;

	adding_radian = (meta->human.fov / SCREEN_WIDTH) * col;
	init_ray(&verti, &horiz, meta, &adding_radian);
	wall = get_point2d_wall(&verti, &horiz, meta, verti.vector);
	colli = convert_collision_data(&(meta->human.point), &wall, &verti);
	colli.dis *= cos(meta->human.vector - verti.vector);
	colli.col = col;
	colli.tex_x = get_tex_x(&wall, colli.dire, meta->tile_size);
	return (colli);
}

void	set_i_and_notwall(int *i, int *notwall)
{
	if (*notwall < 0)
	{
		*notwall = 0;
		*i = 0;
	}
	else
		*i = *notwall;
}

/*
 * @brief 'zoom_ratio' is the number of times the tile is magnified.
 * @brief Example: If the player can see 2 tiles hight, the zoom_ratio is 2.
*/
void	draw_texture_on_each_col(
	t_meta *meta, t_collision *colli, const double *base_dis)
{
	int		i;
	int		color;
	double	zoom_ratio;
	int		notwall;
	double	row;

	zoom_ratio = colli->dis / *base_dis;
	notwall = (SCREEN_HEIGHT - (SCREEN_HEIGHT / zoom_ratio)) / 2;
	set_i_and_notwall(&i, &notwall);
	while (i < SCREEN_HEIGHT - notwall)
	{
		if (is_map(colli->col, i, meta) == true)
		{
			i++;
			continue ;
		}
		if (zoom_ratio < 1)
			row = ((i * zoom_ratio) / SCREEN_HEIGHT) + ((1 - zoom_ratio) / 2);
		else
			row = (i - notwall) / (SCREEN_HEIGHT / zoom_ratio);
		color = cub3d_select_color(meta, colli, row);
		my_mlx_pixel_put(&(meta->mlx), colli->col, i++, color);
	}
}

/*
 * @brief 'base_dis' is the distance that the player just sees the one tile.
*/
void	cub3d_draw_view(t_meta *meta)
{
	int			col;
	t_collision	colli;
	double		base_dis;

	base_dis = (meta->tile_size / 2) / tan(meta->human.fov / 2);
	col = 0;
	while (col < SCREEN_WIDTH)
	{
		colli = get_fov_wall_data(meta, col);
		draw_texture_on_each_col(meta, &colli, &base_dis);
		col++;
	}
}
