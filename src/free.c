/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:24:21 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/29 10:28:55 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_meta(t_meta *meta)
{
	if (meta->north_tex.filepath)
		free(meta->north_tex.filepath);
	if (meta->north_tex.img)
		mlx_destroy_image(meta->mlx.mlx, meta->north_tex.img);
	if (meta->south_tex.filepath)
		free(meta->south_tex.filepath);
	if (meta->south_tex.img)
		mlx_destroy_image(meta->mlx.mlx, meta->south_tex.img);
	if (meta->west_tex.filepath)
		free(meta->west_tex.filepath);
	if (meta->west_tex.img)
		mlx_destroy_image(meta->mlx.mlx, meta->west_tex.img);
	if (meta->east_tex.filepath)
		free(meta->east_tex.filepath);
	if (meta->east_tex.img)
		mlx_destroy_image(meta->mlx.mlx, meta->east_tex.img);
	if (meta->mlx.img)
		mlx_destroy_image(meta->mlx.mlx, meta->mlx.img);
	if (meta->mlx.win)
		mlx_destroy_window(meta->mlx.mlx, meta->mlx.win);
	if (meta->map)
		free_map_null_terminated((void ***)&(meta->map));
}
