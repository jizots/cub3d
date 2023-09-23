/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:45:33 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/23 17:53:24 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keycode.h"

int	cub3d_mlx_keypush(int keycode, t_meta *meta)
{
	if (keycode == KEY_ESC)
		return (my_mlx_close_win(&(meta->mlx)));
	else if (keycode == KEY_PLUS)
	{

	}
	else if (keycode == KEY_MINUS)
	{
	}
	my_mlx_image_clear(&(meta->mlx));
	// ft_draw(meta, meta->mlx);
	return (0);
}