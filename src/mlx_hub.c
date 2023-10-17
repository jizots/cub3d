/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:40:45 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/17 14:39:00 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"

int	loop(t_meta *meta)
{
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
	mlx_hook(meta->mlx.win, 2, 0, cub3d_mlx_keypush, meta);
	mlx_hook(meta->mlx.win, 17, 0, my_mlx_close_win, &(meta->mlx));
	mlx_loop(meta->mlx.mlx);
}
