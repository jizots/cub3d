/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:30:22 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/24 15:28:15 by sotanaka         ###   ########.fr       */
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
# include <mlx.h>
# include <mlx_png.h>

/*-------difine------*/
# define SPACE '0'
# define WALL '1'
# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 800

/*------typedef------*/
typedef struct s_human
{
	t_point2d	position;
	int			vector;
}	t_human;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

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
//mlx
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		my_mlx_create_win(t_mlx *mlx);
int		my_mlx_create_image_addr(t_mlx *mlx);
void	my_mlx_image_clear(t_mlx *mlx);
int		my_mlx_close_win(t_mlx *mlx);

#endif
