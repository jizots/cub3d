/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cub_hub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:40:45 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/20 13:42:04 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "my_mlx.h"
#include "keycode.h"

void	cub3d_push_img_loop(t_meta *meta)
{
	mlx_put_image_to_window(meta->mlx.mlx, meta->mlx.win, meta->mlx.img, 0, 0);
	mlx_loop_hook(meta->mlx.mlx, cub3d_loop, meta);
	mlx_hook(meta->mlx.win, KEY_PRESS, 0, cub3d_mlx_keypush, meta);
	mlx_hook(meta->mlx.win, KEY_RELEASE, 0, cub3d_mlx_keyrelease, meta);
	mlx_hook(meta->mlx.win, 17, 0, my_mlx_close_win, &(meta->mlx));
	mlx_loop(meta->mlx.mlx);
}
