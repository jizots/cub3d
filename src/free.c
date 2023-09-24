/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:24:21 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/24 17:39:06 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_meta(t_meta *meta)
{
	if (meta->north_tex.filepath)
		free(meta->north_tex.filepath);
	if (meta->south_tex.filepath)
		free(meta->south_tex.filepath);
	if (meta->west_tex.filepath)
		free(meta->west_tex.filepath);
	if (meta->east_tex.filepath)
		free(meta->east_tex.filepath);
	if (meta->map)
		free_map_null_terminated((void ***)&(meta->map));
}
