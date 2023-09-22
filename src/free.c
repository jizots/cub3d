/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:24:21 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/22 14:28:33 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_meta(t_meta *meta)
{
	if (meta->north_tex)
		free(meta->north_tex);
	if (meta->south_tex)
		free(meta->south_tex);
	if (meta->west_tex)
		free(meta->west_tex);
	if (meta->east_tex)
		free(meta->east_tex);
	if (meta->map)
		free_map_null_terminated((void ***)&(meta->map));
}
