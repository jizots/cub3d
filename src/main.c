/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:10 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/21 11:50:49 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_meta(t_meta *meta)
{
	meta->north_tex = NULL;
	meta->south_tex = NULL;
	meta->west_tex = NULL;
	meta->east_tex = NULL;
	meta->floor_color = -1;
	meta->ceiling_color = -1;
	meta->map = NULL;
}

int	main(int ac, char *av[])
{
	t_meta	meta;

	if (ac != 2)
		return (printf("Error. Invalid argument\n"));
	init_meta(&meta);
	if (cub3d_parse(av[1], &meta) != 0)
// 		return (1);

	printf("north: %s\n", meta.north_tex);
	printf("south: %s\n", meta.south_tex);
	printf("west: %s\n", meta.west_tex);
	printf("east: %s\n", meta.east_tex);
	printf("floor: %d\n", meta.floor_color);
	printf("ceiling: %d\n", meta.ceiling_color);

	for (int i = 0; meta.map != NULL && meta.map[i] != NULL; i++)
		printf("%s", meta.map[i]);

	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}
