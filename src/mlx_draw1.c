/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:37:03 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/01 13:15:07 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_draw_line_single_color(
	t_point2df *from, t_point2df *to, t_mlx *mlx, int color)
{
	double	radius;
	double	radian;
	int		x;
	int		y;

	radius = hypotenus_of_pytgrs(to->x - from->x, to->y - from->y);
	radian = atan2((to->y - from->y), (to->x - from->x));
	while (radius >= 0)
	{
		x = from->x + (radius * cos(radian));
		y = from->y + (radius * sin(radian));
		my_mlx_pixel_put(mlx, x, y, color);
		radius--;
	}
}

void	my_mlx_draw_circle(t_mlx *mlx, t_point2df center, int radius, int color)
{
	double	x;
	double	y;
	double	degree;

	degree = 0;
	while (degree < 360)
	{
		x = radius * cos(get_radian(degree));
		y = radius * sin(get_radian(degree));
		my_mlx_pixel_put(mlx, (int)(center.x + x), (int)(center.y + y), color);
		degree += 10.0 / radius;
	}
}

void	my_mlx_draw_vector(
	t_mlx *mlx, t_point2df center, double radian, int color)
{
	t_point2df	to;

	to.x = VECTOR_SCALE * cos(radian) + center.x;
	to.y = VECTOR_SCALE * sin(radian) + center.y;
	my_mlx_draw_bresenham_line(mlx, center, to, color);
}
