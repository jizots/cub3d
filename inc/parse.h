/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:28:27 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/18 18:19:40 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/*------include-------*/
/*
open, close, read
*/
# include <fcntl.h>
# include <unistd.h>
# include "cub3d.h"

/*-------difine------*/

/*------typedef------*/
typedef struct s_map
{
	char		type;
	t_point2d	point2d;
}	t_map;

typedef struct s_meta
{
	char		*north_tex;
	char		*south_tex;
	char		*west_tex;
	char		*east_tex;
	int			floor_color;
	int			ceiling_color;
	size_t		width_map;
	size_t		height_map;
	t_map		**map;
	t_mlx		mlx;
}	t_meta;

/*------prototype------*/

#endif