/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cub_init_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:40:33 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/21 12:50:55 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "my_mlx.h"
#include "keycode.h"

void	human_walk_up(t_human *human, t_mlx *mlx, double speed)
{
	t_point2df		old_pos;

	old_pos = human->point;
	human->point.y += sin(human->vector) * speed;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.y = old_pos.y;
	human->point.x += cos(human->vector) * speed;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.x = old_pos.x;
}

void	human_walk_left(t_human *human, t_mlx *mlx, double speed)
{
	t_point2df		old_pos;

	old_pos = human->point;
	human->point.y += sin(human->vector + get_radian(-90)) * speed;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.y = old_pos.y;
	human->point.x += cos(human->vector + get_radian(-90)) * speed;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.x = old_pos.x;
}

void	human_walk_down(t_human *human, t_mlx *mlx, double speed)
{
	t_point2df		old_pos;

	old_pos = human->point;
	human->point.y -= sin(human->vector) * speed;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.y = old_pos.y;
	human->point.x -= cos(human->vector) * speed;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.x = old_pos.x;
}

void	human_walk_right(t_human *human, t_mlx *mlx, double speed)
{
	t_point2df		old_pos;

	old_pos = human->point;
	human->point.y += sin(human->vector + get_radian(90)) * speed;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.y = old_pos.y;
	human->point.x += cos(human->vector + get_radian(90)) * speed;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.x = old_pos.x;
}

void	init_human_position(t_meta *meta)
{
	if (meta->key.key_w == true)
		human_walk_up(&(meta->human), &(meta->mlx), meta->tile_size / 4.0);
	else if (meta->key.key_a == true)
		human_walk_left(&(meta->human), &(meta->mlx), meta->tile_size / 4.0);
	else if (meta->key.key_s == true)
		human_walk_down(&(meta->human), &(meta->mlx), meta->tile_size / 4.0);
	else if (meta->key.key_d == true)
		human_walk_right(&(meta->human), &(meta->mlx), meta->tile_size / 4.0);
	else
	{
		if (meta->key.key_left == true)
			meta->human.vector -= 0.05;
		else if (meta->key.key_right == true)
			meta->human.vector += 0.05;
		if (meta->human.vector < 0)
			meta->human.vector += 2 * M_PI;
		else if (meta->human.vector > 2 * M_PI)
			meta->human.vector -= 2 * M_PI;
	}
}
