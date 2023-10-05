/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:10 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/04 17:52:31 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_meta_data(t_meta *meta)
{
	for (int i = 0; meta->map != NULL && meta->map[i] != NULL; i++)
		printf("%s", meta->map[i]);
	printf("Human:x_%f y_%f\n", meta->human.point.x, meta->human.point.y);
	printf("vector:%f\n", meta->human.vector);
	printf("width:%zu height:%zu\n", meta->width_map, meta->height_map);
}

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
	cub3d_push_img_loop(&meta);
	free_meta(&meta);
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q cub3D");
}