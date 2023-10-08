/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:40:25 by hotph             #+#    #+#             */
/*   Updated: 2023/10/08 11:01:31 by hotph            ###   ########.fr       */
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

static double	get_tex_x(
	t_point2df *wall, const char dire, const int tile_size)
{
	double	integer;

	if (dire == 'N' || dire == 'S')
		return (modf((wall->x / tile_size), &integer));
	else
		return (modf((wall->y / tile_size), &integer));
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
	colli.col = col;
	colli.tex_x = get_tex_x(&wall, colli.dire, meta->tile_size);
	return (colli);
}

int	cub3d_select_color(
	t_meta *meta, t_collision *colli, int row, const double zoom_ratio)
{
	int		color;
	(void)meta;
	(void)zoom_ratio;
	(void)colli;
	(void)row;

	color = 0x00FFFFFF;//default color
	return (color);
}

int	simple_color_set(
	t_meta *meta, t_collision *colli, int row, const double zoom_ratio)
{
	int		color;
	(void)meta;
	(void)zoom_ratio;
	(void)row;
	
	if (colli->dire == 'N')
		color = 0x00FF0000;
	else if (colli->dire == 'S')
		color = 0x0000FF00;
	else if (colli->dire == 'W')
		color = 0x000000FF;
	else if (colli->dire == 'E')
		color = 0x00FFFF00;
	else
		color = 0x00FFFFFF;
	return (color);
}

bool	is_map(int x, int y, t_meta *meta)
{
	if (x < (meta->tile_size * meta->width_map)
		&& y < (meta->tile_size * meta->height_map))
		return (true);
	return (false);
}

void	draw_texture_on_each_col(
	t_meta *meta, t_collision *colli, const double *base_dis)
{
	int		i;
	int		color;
	double	zoom_ratio;
	int		ignore;

	zoom_ratio = *base_dis / colli->dis;
	ignore = (SCREEN_HEIGHT - (SCREEN_HEIGHT * zoom_ratio)) / 2;
	if (ignore < 0)
		i = 0;
	else
		i = ignore;
	while (i < SCREEN_HEIGHT)
	{
		if (is_map(colli->col, i, meta) == true)
			;
		else
		{
			color =  simple_color_set(meta, colli, i, zoom_ratio); //cub3d_select_color(meta, colli, i, zoom_ratio);
			my_mlx_pixel_put(&(meta->mlx), colli->col, i, color);
		}
		i++;
		if (i >= SCREEN_HEIGHT - ignore)
			break ;
	}
}

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
