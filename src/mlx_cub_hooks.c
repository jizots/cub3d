/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cub_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:45:33 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/20 13:45:46 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "my_mlx.h"
#include "keycode.h"

static void	human_walk(int keycode, t_key *key)
{
	if (keycode == KEY_S)
		is_key_any_pressed(KEY_PRESS, &(key->key_s));
	else if (keycode == KEY_W)
		is_key_any_pressed(KEY_PRESS, &(key->key_w));
	else if (keycode == KEY_D)
		is_key_any_pressed(KEY_PRESS, &(key->key_d));
	else if (keycode == KEY_A)
		is_key_any_pressed(KEY_PRESS, &(key->key_a));
}

int	cub3d_mlx_keypush(int keycode, t_meta *meta)
{
	if (keycode == KEY_ESC)
	{
		free_meta(meta);
		return (my_mlx_close_win(&(meta->mlx)));
	}
	else if ((KEY_A <= keycode && keycode <= KEY_D) || keycode == KEY_W)
		human_walk(keycode, &(meta->key));
	else if (keycode == KEY_LEFT)
		is_key_any_pressed(KEY_PRESS, &(meta->key.key_left));
	else if (keycode == KEY_RIGHT)
		is_key_any_pressed(KEY_PRESS, &(meta->key.key_right));
	return (0);
}

int	cub3d_mlx_keyrelease(int keycode, t_meta *meta)
{
	if (keycode == KEY_W)
		is_key_any_pressed(KEY_RELEASE, &(meta->key.key_w));
	else if (keycode == KEY_A)
		is_key_any_pressed(KEY_RELEASE, &(meta->key.key_a));
	else if (keycode == KEY_S)
		is_key_any_pressed(KEY_RELEASE, &(meta->key.key_s));
	else if (keycode == KEY_D)
		is_key_any_pressed(KEY_RELEASE, &(meta->key.key_d));
	else if (keycode == KEY_LEFT)
		is_key_any_pressed(KEY_RELEASE, &(meta->key.key_left));
	else if (keycode == KEY_RIGHT)
		is_key_any_pressed(KEY_RELEASE, &(meta->key.key_right));
	return (0);
}

int	cub3d_loop(t_meta *meta)
{
	draw_sky_and_ground(meta);
	draw_minimap(meta);
	init_human_position(meta);
	cub3d_draw_view(meta);
	cub3d_draw_human(meta);
	mlx_put_image_to_window(meta->mlx.mlx, meta->mlx.win, meta->mlx.img, 0, 0);
	return (0);
}
