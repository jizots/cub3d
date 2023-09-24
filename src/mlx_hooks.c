/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:45:33 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/24 15:21:37 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keycode.h"

void	human_walk(t_meta *meta, int keycode)
{
	if (keycode == KEY_DOWN)
		meta->human.position.x -= 0.1;
	else if (keycode == KEY_UP)
		meta->human.position.x += 0.1;
	else if (keycode == KEY_RIGHT)
		meta->human.position.y += 0.1;
	else if (keycode == KEY_LEFT)
		meta->human.position.y -= 0.1;
}

int	cub3d_mlx_keypush(int keycode, t_meta *meta)
{
	if (keycode == KEY_ESC)
		return (my_mlx_close_win(&(meta->mlx)));
	else if (KEY_LEFT <= keycode && keycode <= KEY_DOWN)
		human_walk(meta, keycode);
	else if (keycode == KEY_MINUS)
	{
	}
	my_mlx_image_clear(&(meta->mlx));
	// ft_draw(meta, meta->mlx);
	return (0);
}