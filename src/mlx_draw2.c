/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:36:02 by hotph             #+#    #+#             */
/*   Updated: 2023/09/29 19:00:22 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

void	my_mlx_draw_square(t_mlx *mlx, t_point2d top_left, int size, int color)
{
	int	xi;
	int	yi;
	int	sx;
	int	sy;

	sx = (int)round(top_left.x) * size;
	sy = (int)round(top_left.y) * size;
	yi = 0;
	while (yi < size)
	{
		xi = 0;
		while (xi < size)
		{
			my_mlx_pixel_put(mlx, sx + xi, sy + yi, color);
			xi++;
		}
		yi++;
	}
}
