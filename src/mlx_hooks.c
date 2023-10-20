/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:45:33 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/20 11:26:11 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "my_mlx.h"
#include "keycode.h"

static void	human_walk(int keycode)
{
	if (keycode == KEY_S)
		is_key_S_pressed(KEY_PRESS);
	else if (keycode == KEY_W)
		is_key_W_pressed(KEY_PRESS);
	else if (keycode == KEY_D)
		is_key_D_pressed(KEY_PRESS);
	else if (keycode == KEY_A)
		is_key_A_pressed(KEY_PRESS);
}

static void	human_vector_rotate(t_human *human, int keycode)
{
	if (keycode == KEY_LEFT)
		human->vector -= 0.07;
	else if (keycode == KEY_RIGHT)
		human->vector += 0.07;
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
		human_walk(keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		human_vector_rotate(&(meta->human), keycode);
	return (0);
}

int	cub3d_mlx_keyrelease(int keycode, t_meta *meta)
{
	(void)meta;
	if (keycode == KEY_W)
		is_key_W_pressed(KEY_RELEASE);
	else if (keycode == KEY_A)
		is_key_A_pressed(KEY_RELEASE);
	else if (keycode == KEY_S)
		is_key_S_pressed(KEY_RELEASE);
	else if (keycode == KEY_D)
		is_key_D_pressed(KEY_RELEASE);
	return (0);
}
