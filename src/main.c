/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:10 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/24 16:27:55 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_meta(t_meta *meta)
{
	meta->floor_color = -1;
	meta->ceiling_color = -1;
	meta->map = NULL;
	meta->mlx.mlx = NULL;
	meta->mlx.win = NULL;
	meta->mlx.img = NULL;
	meta->mlx.addr = NULL;
}

void	test_human_circle(t_meta *meta)
{

}


int	main(int ac, char *av[])
{
	t_meta	meta;

	if (ac != 2)
		return (printf("Error. Invalid argument\n"));
	init_meta(&meta);
	if (cub3d_parse(av[1], &meta) != 0)
		return (1);

for (int i = 0; meta.map != NULL && meta.map[i] != NULL; i++)
	printf("%s", meta.map[i]);
printf("Human:x_%f y_%f\n", meta.human.position.x, meta.human.position.y);

	if (cub3d_create_win(&meta) != 0)
		;
	test_human_circle(&meta);
	cub3d_push_img_loop(&meta);
	free_meta(&meta);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q cub3D");
}
