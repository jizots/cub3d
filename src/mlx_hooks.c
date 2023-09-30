/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:45:33 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/30 15:02:13 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keycode.h"

void	human_walk(t_meta *meta, int keycode)
{
	t_point2d	old_pos;
	unsigned int	color;

	old_pos = meta->human.point;
	if (keycode == KEY_DOWN)
	{
		meta->human.point.y -= sin(meta->human.vector) * MOVE_SPEED;
		meta->human.point.x -= cos(meta->human.vector) * MOVE_SPEED;
	}
	else if (keycode == KEY_UP)
	{
		meta->human.point.y += sin(meta->human.vector) * MOVE_SPEED;
		meta->human.point.x += cos(meta->human.vector) * MOVE_SPEED;
	}
	else if (keycode == KEY_RIGHT)
	{
		meta->human.point.y += sin(meta->human.vector + get_radian(90)) * MOVE_SPEED;
		meta->human.point.x += cos(meta->human.vector + get_radian(90)) * MOVE_SPEED;
	}
	else if (keycode == KEY_LEFT)
	{
		meta->human.point.y += sin(meta->human.vector + get_radian(-90)) * MOVE_SPEED;
		meta->human.point.x += cos(meta->human.vector + get_radian(-90)) * MOVE_SPEED;
	}
	color = *((unsigned int *)(meta->mlx.addr + ((int)meta->human.point.y * meta->mlx.line_length
		+ (int)meta->human.point.x * (meta->mlx.bits_per_pixel / 8))));
	if (color == WALL_COLOR)
		meta->human.point = old_pos;
}

void	human_vector_rotate(t_meta *meta, int keycode)
{
	if (keycode == KEY_A)
		meta->human.vector -= 0.1;
	else if (keycode == KEY_D)
		meta->human.vector += 0.1;
	if (meta->human.vector < 0)
		meta->human.vector += 2 * M_PI;
	else if (meta->human.vector > 2 * M_PI)
		meta->human.vector -= 2 * M_PI;
}

int	cub3d_mlx_keypush(int keycode, t_meta *meta)
{
	if (keycode == KEY_ESC)
		return (my_mlx_close_win(&(meta->mlx)));
	else if (KEY_LEFT <= keycode && keycode <= KEY_UP)
		human_walk(meta, keycode);
	else if (keycode == KEY_A || keycode == KEY_D)
		human_vector_rotate(meta, keycode);
	my_mlx_image_clear(&(meta->mlx));
	draw_wall_of_map(meta);
	draw_human(meta);
	mlx_put_image_to_window(meta->mlx.mlx, meta->mlx.win, meta->mlx.img, 0, 0);
	return (0);
}