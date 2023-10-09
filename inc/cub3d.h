/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:30:22 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/09 16:42:31 by hotph            ###   ########.fr       */
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
# include "../../libsft/libsft/includes/libsft.h"
# include "../../libsft/libsft/includes/libsft_utils.h"
# include "error3d.h"
# include "my_mlx.h"

/*-------difine------*/
# define SPACE '0'
# define WALL '1'
# define MAP_WIDTH 500
# define MAP_HEIGHT 500
# define HUMAN_RADIUS 5
# define MOVE_SPEED 3
# define HUMAN_COLOR 0x00FF0000
# define WALL_COLOR 0x00FFFFFF
# define RAY_COLOR 0xF58220

/*
About coordinate system.
The origin is the upper left corner.
The x-axis is the horizontal line.
X increases to the right of window.
The y-axis is the vertical line.
Y increases to the bottom of window.
The unit is pixel.
Degrees are measured clockwise from the x-axis.
*/

/*------typedef------*/
/*
 * @brief 'vector' is direction the human is looking at. Radian value.
 * @brief 'fov' means [field of view].
 * @brief 'color' is the drawing color of the human.
*/
typedef struct s_human
{
	t_point2df	point;
	double		vector;
	double		fov;
	int			color;
}	t_human;

/*
 * @brief	'intersection' is the point where the ray hits the wall.
 * @brief	'tan_ray' is the tangent of the ray. It's used to calculate the
 *  x or y coordinate of the intersection.
 * @brief	'flag' is used to determine 
 * @brief	whether the ray stand on vertical or horizontal intersection.
*/
typedef struct s_ray
{
	t_point2df	intersec;
	double		vector;
	int			flag;
}	t_ray;

/*
 * @brief	'dis' means distance. Between human and wall.
 * @brief	'col' means column which column to projection.
 * @brief	'dire' means 'direction',
 * @brief	and indicates the direction of the wall that Ray hit.
*/
typedef struct s_collision
{
	double	dis;
	int		col;
	char	dire;
	double	tex_x;
}	t_collision;

typedef struct s_meta
{
	t_tex	north_tex;
	t_tex	south_tex;
	t_tex	west_tex;
	t_tex	east_tex;
	int		floor_color;
	int		ceiling_color;
	double	tile_size;
	char	**map;
	t_human	human;
	size_t	width_map;
	size_t	height_map;
	t_mlx	mlx;
}	t_meta;

/*------prototype------*/
int		cub3d_parse(char *file_name, t_meta *meta);
int		cub3d_create_win(t_meta *meta);
void	cub3d_draw_map(t_meta *meta);
void	cub3d_draw_view(t_meta *meta);
void	cub3d_draw_human(t_meta *meta);
void	cub3d_push_img_loop(t_meta *meta);
int		cub3d_mlx_keypush(int keycode, t_meta *meta);
void	free_meta(t_meta *meta);

#endif