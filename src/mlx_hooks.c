/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:45:33 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/17 14:47:05 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "keycode.h"

void	human_walk2(t_human *human, t_mlx *mlx, int keycode, t_point2df old_pos)
{
	if (keycode == KEY_D)
	{
		human->point.y += sin(human->vector + get_radian(90)) * MOVE_SPEED;
		if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
			human->point.y = old_pos.y;
		human->point.x += cos(human->vector + get_radian(90)) * MOVE_SPEED;
		if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
			human->point.x = old_pos.x;
	}
	else if (keycode == KEY_A)
	{
		human->point.y += sin(human->vector + get_radian(-90)) * MOVE_SPEED;
		if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
			human->point.y = old_pos.y;
		human->point.x += cos(human->vector + get_radian(-90)) * MOVE_SPEED;
		if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
			human->point.x = old_pos.x;
	}
}

void	human_walk(t_human *human, t_mlx *mlx, int keycode)
{
	t_point2df		old_pos;

	old_pos = human->point;
	if (keycode == KEY_S)
	{
		human->point.y -= sin(human->vector) * MOVE_SPEED;
		if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
			human->point.y = old_pos.y;
		human->point.x -= cos(human->vector) * MOVE_SPEED;
		if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
			human->point.x = old_pos.x;
	}
	else if (keycode == KEY_W)
	{
		human->point.y += sin(human->vector) * MOVE_SPEED;
		if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
			human->point.y = old_pos.y;
		human->point.x += cos(human->vector) * MOVE_SPEED;
		if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
			human->point.x = old_pos.x;
	}
	else
		human_walk2(human, mlx, keycode, old_pos);
}

void	human_vector_rotate(t_human *human, int keycode)
{
	if (keycode == KEY_LEFT)
		human->vector -= 0.1;
	else if (keycode == KEY_RIGHT)
		human->vector += 0.1;
	if (human->vector < 0)
		human->vector += 2 * M_PI;
	else if (human->vector > 2 * M_PI)
		human->vector -= 2 * M_PI;
}

int	cub3d_mlx_keypush(int keycode, t_meta *meta)
{
	draw_minimap(meta);
	if (keycode == KEY_ESC)
	{
		free_meta(meta);
		return (my_mlx_close_win(&(meta->mlx)));
	}
	else if ((KEY_A <= keycode && keycode <= KEY_D) || keycode == KEY_W)
		human_walk(&(meta->human), &(meta->mlx), keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		human_vector_rotate(&(meta->human), keycode);
	return (0);
}
