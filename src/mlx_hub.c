/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:40:45 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/20 11:19:28 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "my_mlx.h"
#include "keycode.h"

void	human_walk_up(t_human *human, t_mlx *mlx)
{
	t_point2df		old_pos;

	old_pos = human->point;
	human->point.y += sin(human->vector) * MOVE_SPEED;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.y = old_pos.y;
	human->point.x += cos(human->vector) * MOVE_SPEED;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.x = old_pos.x;
}

void	human_walk_left(t_human *human, t_mlx *mlx)
{
	t_point2df		old_pos;

	old_pos = human->point;
	human->point.y += sin(human->vector + get_radian(-90)) * MOVE_SPEED;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.y = old_pos.y;
	human->point.x += cos(human->vector + get_radian(-90)) * MOVE_SPEED;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.x = old_pos.x;
}

void	human_walk_down(t_human *human, t_mlx *mlx)
{
	t_point2df		old_pos;

	old_pos = human->point;
	human->point.y -= sin(human->vector) * MOVE_SPEED;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.y = old_pos.y;
	human->point.x -= cos(human->vector) * MOVE_SPEED;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.x = old_pos.x;
}

void	human_walk_right(t_human *human, t_mlx *mlx)
{
	t_point2df		old_pos;

	old_pos = human->point;
	human->point.y += sin(human->vector + get_radian(90)) * MOVE_SPEED;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.y = old_pos.y;
	human->point.x += cos(human->vector + get_radian(90)) * MOVE_SPEED;
	if (is_wall((t_point2di){human->point.x, human->point.y}, mlx))
		human->point.x = old_pos.x;
}

int	loop(t_meta *meta)
{
	if (is_key_W_pressed(42))
		human_walk_up(&(meta->human), &(meta->mlx));
	if (is_key_A_pressed(42))
		human_walk_left(&(meta->human), &(meta->mlx));
	if (is_key_S_pressed(42))
		human_walk_down(&(meta->human), &(meta->mlx));
	if (is_key_D_pressed(42))
		human_walk_right(&(meta->human), &(meta->mlx));
	draw_sky_and_ground(meta);
	draw_minimap(meta);
	cub3d_draw_view(meta);
	cub3d_draw_human(meta);
	mlx_put_image_to_window(meta->mlx.mlx, meta->mlx.win, meta->mlx.img, 0, 0);
	return (0);
}

void	cub3d_push_img_loop(t_meta *meta)
{
	mlx_put_image_to_window(meta->mlx.mlx, meta->mlx.win, meta->mlx.img, 0, 0);
	mlx_loop_hook(meta->mlx.mlx, loop, meta);
	mlx_hook(meta->mlx.win, KEY_PRESS, 0, cub3d_mlx_keypush, meta);
	mlx_hook(meta->mlx.win, KEY_RELEASE, 0, cub3d_mlx_keyrelease, meta);
	mlx_hook(meta->mlx.win, 17, 0, my_mlx_close_win, &(meta->mlx));
	mlx_loop(meta->mlx.mlx);
}
