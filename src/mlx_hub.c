/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:40:45 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/23 17:53:24 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_push_img_loop(t_meta *meta)
{
	mlx_put_image_to_window(meta->mlx.mlx, meta->mlx.win, meta->mlx.img, 0, 0);
	mlx_hook(meta->mlx.win, 2, 0, cub3d_mlx_keypush, meta);
	mlx_hook(meta->mlx.win, 17, 0, my_mlx_close_win, &(meta->mlx));
	mlx_loop(meta->mlx.mlx);
}

int	cub3d_create_win(t_meta *meta)
{
	if (my_mlx_create_win(&(meta->mlx)) != 0)
		return (1);
	if (my_mlx_create_image_addr(&(meta->mlx)) != 0)
		return (1);
	return (0);
}
