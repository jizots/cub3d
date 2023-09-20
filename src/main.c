/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:10 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/20 13:12:25 by sotanaka         ###   ########.fr       */
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

// int	main(int ac, char *av[])
// {
// 	t_meta	meta;

// 	if (ac != 2)
// 		return (printf("Error. Invalid argument\n"));
// 	init_meta(&meta);
// 	if (cub3d_parse(av[1], &meta) != 0)
// 		return (1);

// }