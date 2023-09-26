/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:10 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/26 14:38:44 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_meta_data(t_meta *meta)
{
	for (int i = 0; meta->map != NULL && meta->map[i] != NULL; i++)
		printf("%s", meta->map[i]);
	printf("Human:x_%f y_%f\n", meta->human.position.x, meta->human.position.y);
	printf("vector:%f\n", meta->human.vector);
	printf("width:%zu height:%zu\n", meta->width_map, meta->height_map);
}

static int	init_meta(t_meta *meta)
{
	meta->floor_color = -1;
	meta->ceiling_color = -1;
	meta->map = NULL;
	meta->mlx.mlx = mlx_init();
	if (meta->mlx.mlx == NULL)
		return (perror_wrap("Error. at mlx_int", 1));
	meta->mlx.win = NULL;
	meta->mlx.img = NULL;
	meta->mlx.addr = NULL;
	meta->north_tex.filepath = NULL;
	meta->south_tex.filepath = NULL;
	meta->west_tex.filepath = NULL;
	meta->east_tex.filepath = NULL;
	return (0);
}

void	test_human_circle(t_meta *meta)
{
	t_point2d	center;
	int			radius;
	int			color;

	center.x = meta->human.position.x * 10;
	center.y = meta->human.position.y * 10;
	radius = 10;
	color = 0x00FF0000;
	my_mlx_draw_circle(&(meta->mlx), center, radius, color);
}

void	test_human_vector(t_meta *meta)
{
	t_point2d	center;
	int			color;

	center.x = meta->human.position.x * 10;
	center.y = meta->human.position.y * 10;
	color = 0x00FF0000;
	my_mlx_draw_vector(&(meta->mlx), center, meta->human.vector, color);
}

int	main(int ac, char *av[])
{
	t_meta	meta;

	if (ac != 2)
		return (printf("Error. Invalid argument\n"));
	if (init_meta(&meta) != 0)
		return (1);
	if (cub3d_parse(av[1], &meta) != 0)
		return (1);
	if (cub3d_create_win(&meta) != 0)
		;
	test_human_circle(&meta);
	test_human_vector(&meta);
	cub3d_push_img_loop(&meta);
	free_meta(&meta);
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q cub3D");
}