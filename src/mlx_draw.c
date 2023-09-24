/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:37:03 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/24 17:56:18 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_draw_circle(t_meta *meta, t_point2d center, int radius, int color)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = radius;
	d = 1 - radius;
	while (x <= y)
	{
		my_mlx_pixel_put(&(meta->mlx), center.x + x, center.y + y, color);
		my_mlx_pixel_put(&(meta->mlx), center.x + x, center.y - y, color);
		my_mlx_pixel_put(&(meta->mlx), center.x - x, center.y + y, color);
		my_mlx_pixel_put(&(meta->mlx), center.x - x, center.y - y, color);
		my_mlx_pixel_put(&(meta->mlx), center.x + y, center.y + x, color);
		my_mlx_pixel_put(&(meta->mlx), center.x + y, center.y - x, color);
		my_mlx_pixel_put(&(meta->mlx), center.x - y, center.y + x, color);
		my_mlx_pixel_put(&(meta->mlx), center.x - y, center.y - x, color);
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
}