/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:45:33 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/01 13:46:56 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keycode.h"

void	human_walk(t_human *human, t_mlx *mlx, int keycode)
{
	t_point2df		old_pos;
	unsigned int	color;

	old_pos = human->point;
	if (keycode == KEY_DOWN)
	{
		human->point.y -= sin(human->vector) * MOVE_SPEED;
		human->point.x -= cos(human->vector) * MOVE_SPEED;
	}
	else if (keycode == KEY_UP)
	{
		human->point.y += sin(human->vector) * MOVE_SPEED;
		human->point.x += cos(human->vector) * MOVE_SPEED;
	}
	else if (keycode == KEY_RIGHT)
	{
		human->point.y += sin(human->vector + get_radian(90)) * MOVE_SPEED;
		human->point.x += cos(human->vector + get_radian(90)) * MOVE_SPEED;
	}
	else if (keycode == KEY_LEFT)
	{
		human->point.y += sin(human->vector + get_radian(-90)) * MOVE_SPEED;
		human->point.x += cos(human->vector + get_radian(-90)) * MOVE_SPEED;
	}
	color = *((unsigned int *)(mlx->addr + ((int)human->point.y * mlx->line_length
		+ (int)human->point.x * (mlx->bits_per_pixel / 8))));
	if (color == WALL_COLOR)
		human->point = old_pos;
}

void	human_vector_rotate(t_human *human, int keycode)
{
	if (keycode == KEY_A)
		human->vector -= 0.1;
	else if (keycode == KEY_D)
		human->vector += 0.1;
	if (human->vector < 0)
		human->vector += 2 * M_PI;
	else if (human->vector > 2 * M_PI)
		human->vector -= 2 * M_PI;
}

int	cub3d_mlx_keypush(int keycode, t_meta *meta)
{
	my_mlx_image_clear(&(meta->mlx));
	draw_wall_of_map(meta);
	if (keycode == KEY_ESC)
		return (my_mlx_close_win(&(meta->mlx)));
	else if (KEY_LEFT <= keycode && keycode <= KEY_UP)
		human_walk(&(meta->human), &(meta->mlx), keycode);
	else if (keycode == KEY_A || keycode == KEY_D)
		human_vector_rotate(&(meta->human), keycode);
	draw_human(meta);
	mlx_put_image_to_window(meta->mlx.mlx, meta->mlx.win, meta->mlx.img, 0, 0);
	return (0);
}