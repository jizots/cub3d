/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:30:22 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/26 19:05:38 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*------include-------*/
/*
open, close, read, write, printf, malloc, free, perror, strerror, exit
• All functions of the math library (-lm man man 3 math)
• All functions of the MinilibX
*/
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include "../../libsft/libsft/includes/libsft.h"
# include "../../libsft/libsft/includes/libsft_utils.h"
# include "error3d.h"
# include "my_mlx.h"

/*-------difine------*/
# define SPACE '0'
# define WALL '1'
# define MINI_MAP_SCALE 0.2

/*------typedef------*/
typedef struct s_human
{
	t_point2d	position;
	double		vector;
}	t_human;

typedef struct s_tex
{
	void	*img;
	char	*filepath;
	int		img_width;
	int		img_height;
}	t_tex;

typedef struct s_meta
{
	t_tex	north_tex;
	t_tex	south_tex;
	t_tex	west_tex;
	t_tex	east_tex;
	int		floor_color;
	int		ceiling_color;
	double	scale;
	char	**map;
	t_human	human;
	size_t	width_map;
	size_t	height_map;
	t_mlx	mlx;
}	t_meta;

/*------prototype------*/
int		cub3d_parse(char *file_name, t_meta *meta);
void	free_meta(t_meta *meta);
int		cub3d_create_win(t_meta *meta);
void	cub3d_push_img_loop(t_meta *meta);
int		cub3d_mlx_keypush(int keycode, t_meta *meta);

void	test_human_circle(t_meta *meta);
void	test_human_vector(t_meta *meta);

#endif
