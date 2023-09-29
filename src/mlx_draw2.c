/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:36:02 by hotph             #+#    #+#             */
/*   Updated: 2023/09/28 14:54:42 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_draw_square(t_mlx *mlx, t_point2d center, int size, int color)
{
	int	x;
	int	y;
	int	cx;
	int	cy;

	cx = (int)round(center.x);
	cy = (int)round(center.y);
	y = cy - size / 2;
	while (y < cy + size / 2)
	{
		x = cx - size / 2;
		while (x < cx + size / 2)
		{
			my_mlx_pixel_put(mlx, x, y, color);
			x++;
		}
		y++;
	}
}
