/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:57:27 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/27 12:08:04 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

/*------include-------*/
# include "../../libsft/libsft/includes/libsft.h"
# include "../../libsft/libsft/includes/libsft_utils.h"
# include <mlx.h>
# include <mlx_png.h>

/*-------difine------*/
# define SCREEN_WIDTH 900
# define SCREEN_HEIGHT 900

/*------typedef------*/
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

typedef struct s_bresenham
{
	t_point2d	p1;
	t_point2d	p2;
	int			deltax;
	int			deltay;
	double		slope;
	int			set_x;
	int			set_y;
	int			gap;
	int			e2;
}	t_bresenham;

/*------prototype------*/
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		my_mlx_create_win(t_mlx *mlx);
int		my_mlx_create_image_addr(t_mlx *mlx);
void	my_mlx_image_clear(t_mlx *mlx);
int		my_mlx_close_win(t_mlx *mlx);
void	my_mlx_draw_circle(t_mlx *mlx, t_point2d center, int radius, int color);
void	my_mlx_draw_vector(t_mlx *mlx, t_point2d center, double radian, int color);
void	my_mlx_draw_line_single_color(t_point2d *from, t_point2d *to, t_mlx *mlx, int color);
void	my_mlx_draw_bresenham_line(t_mlx *mlx, t_point2d p1, t_point2d p2, int color);

#endif