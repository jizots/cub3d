/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:45:33 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/26 14:27:21 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keycode.h"

void	human_walk(t_meta *meta, int keycode)
{
	if (keycode == KEY_DOWN)
	{
		meta->human.position.y -= sin(meta->human.vector);
		meta->human.position.x -= cos(meta->human.vector);
	}
	else if (keycode == KEY_UP)
	{
		meta->human.position.y += sin(meta->human.vector);
		meta->human.position.x += cos(meta->human.vector);
	}
	else if (keycode == KEY_RIGHT)
	{
		meta->human.position.y += sin(meta->human.vector + get_radian(90));
		meta->human.position.x += cos(meta->human.vector + get_radian(90));
	}
	else if (keycode == KEY_LEFT)
	{
		meta->human.position.y += sin(meta->human.vector + get_radian(-90));
		meta->human.position.x += cos(meta->human.vector + get_radian(-90));
	}
}

void	human_vector_rotate(t_meta *meta, int keycode)
{
	if (keycode == KEY_A)
		meta->human.vector -= 0.1;
	else if (keycode == KEY_D)
		meta->human.vector += 0.1;
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
test_human_circle(meta);
test_human_vector(meta);
	// ft_draw(meta, meta->mlx);
mlx_put_image_to_window(meta->mlx.mlx, meta->mlx.win, meta->mlx.img, 0, 0);
	return (0);
}