/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:52:29 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/26 19:23:39 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	blesenham_line1(t_mlx *mlx, t_bresenham *brs, int color)
{
	brs->gap = 0;
	while (brs->set_x <= brs->p2.x)
	{
		my_mlx_pixel_put(mlx, brs->set_x, brs->set_y, color);
		brs->gap += (2 * brs->deltay);
		if (brs->gap >= brs->deltax)
		{
			if (brs->slope > 0)
			{
				brs->set_y += 1;
				brs->gap -= (2 * brs->deltax);
			}
			else
			{
				brs->set_y -= 1;
				brs->gap -= (2 * brs->deltax);
			}
		}
		brs->set_x += 1;
	}
}

void	my_mlx_draw_blesenham_line(t_mlx *mlx, t_point2d p1, t_point2d p2, int color)
{
	t_bresenham	brs;

	brs.p1 = p1;
	brs.p2 = p2;
	brs.set_x = p1.x;
	brs.set_y = p1.y;
	brs.deltax = p2.x - p1.x;
	brs.deltay = p2.y - p1.y;
	brs.slope = brs.deltay / brs.deltax;
	if (-1 <= brs.slope && brs.slope <= 1 && brs.deltax > 0)
		bresenham_line1(&brs);
	else
		bresenham_line2(&brs);
}