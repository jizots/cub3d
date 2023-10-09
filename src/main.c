/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:10 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/09 16:27:46 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_meta(t_meta *meta)
{
	ft_bzero(meta, sizeof(t_meta));
	meta->floor_color = -1;
	meta->ceiling_color = -1;
	meta->mlx.mlx = mlx_init();
	if (meta->mlx.mlx == NULL)
		return (perror_wrap("Error. at mlx_int", 1));
	meta->human.color = HUMAN_COLOR;
	meta->human.fov = M_PI / 3;
	return (0);
}

int	main(int ac, char *av[])
{
	t_meta	meta;

	if (ac != 2)
		return (printf("Error.\nInvalid argument\n"));
	if (init_meta(&meta) != 0)
		return (1);
	if (cub3d_parse(av[1], &meta) != 0)
		return (1);
	if (cub3d_create_win(&meta) != 0)
		return (1);
	cub3d_draw_map(&meta);
	cub3d_draw_view(&meta);
	cub3d_draw_human(&meta);
	cub3d_push_img_loop(&meta);
	free_meta(&meta);
	my_mlx_close_win(&(meta.mlx));
	return (0);
}

// __attribute__((destructor))
// static void destructor()
// {
// 	system("leaks -q cub3D");
// }