/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_bresenham.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:52:29 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/01 13:15:07 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

void	bresenham_line_degree_315_45(t_mlx *mlx, t_bresenham *brs, int color)
{
	if (brs->minus_slope < 0)
		brs->deltax *= -1;
	brs->gap = 0;
	while (brs->set_x <= brs->p2.x)
	{
		my_mlx_pixel_put(mlx, brs->set_x, brs->set_y, color);
		brs->gap += (2 * brs->deltay);
		if (brs->gap >= brs->deltax && brs->minus_slope >= 0)
		{
			brs->set_y += 1;
			brs->gap -= (2 * brs->deltax);
		}
		else if (brs->gap <= brs->deltax && brs->minus_slope < 0)
		{
			brs->set_y -= 1;
			brs->gap -= (2 * brs->deltax);
		}
		brs->set_x += 1;
	}
}

void	bresenham_line_degree_135_225(t_mlx *mlx, t_bresenham *brs, int color)
{
	if (brs->minus_slope < 0)
		brs->deltax *= -1;
	brs->gap = 0;
	while (brs->set_x >= brs->p2.x)
	{
		my_mlx_pixel_put(mlx, brs->set_x, brs->set_y, color);
		brs->gap += (2 * brs->deltay);
		if (brs->gap <= brs->deltax && brs->minus_slope >= 0)
		{
			brs->set_y -= 1;
			brs->gap -= (2 * brs->deltax);
		}
		else if (brs->gap >= brs->deltax && brs->minus_slope < 0)
		{
			brs->set_y += 1;
			brs->gap -= (2 * brs->deltax);
		}
		brs->set_x -= 1;
	}
}

void	bresenham_line_degree_45_135(t_mlx *mlx, t_bresenham *brs, int color)
{
	if (brs->minus_slope < 0)
		brs->deltay *= -1;
	brs->gap = 0;
	while (brs->set_y <= brs->p2.y)
	{
		my_mlx_pixel_put(mlx, brs->set_x, brs->set_y, color);
		brs->gap += (2 * brs->deltax);
		if (brs->gap >= brs->deltay && brs->minus_slope >= 0)
		{
			brs->set_x += 1;
			brs->gap -= (2 * brs->deltay);
		}
		else if (brs->minus_slope < 0 && brs->gap <= brs->deltay)
		{
			brs->set_x -= 1;
			brs->gap -= (2 * brs->deltay);
		}
		brs->set_y += 1;
	}
}

void	bresenham_line_degree_225_315(t_mlx *mlx, t_bresenham *brs, int color)
{
	if (brs->minus_slope < 0)
		brs->deltay *= -1;
	brs->gap = 0;
	while (brs->set_y >= brs->p2.y)
	{
		my_mlx_pixel_put(mlx, brs->set_x, brs->set_y, color);
		brs->gap += (2 * brs->deltax);
		if (brs->gap <= brs->deltay && brs->minus_slope >= 0)
		{
			brs->set_x -= 1;
			brs->gap -= (2 * brs->deltay);
		}
		else if (brs->gap >= brs->deltay && brs->minus_slope < 0)
		{
			brs->set_x += 1;
			brs->gap -= (2 * brs->deltay);
		}
		brs->set_y -= 1;
	}
}

void	my_mlx_draw_bresenham_line(
	t_mlx *mlx, t_point2df p1, t_point2df p2, int color)
{
	t_bresenham	brs;

	brs.p1 = p1;
	brs.p2 = p2;
	brs.set_x = round(p1.x);
	brs.set_y = round(p1.y);
	brs.deltax = round(p2.x - p1.x);
	brs.deltay = round(p2.y - p1.y);
	brs.fslope = (double)brs.deltay / (double)brs.deltax;
	if (brs.fslope < 0)
		brs.minus_slope = -1;
	else
		brs.minus_slope = 1;
	if (brs.deltax == 0 || brs.deltay == 0)
		my_mlx_draw_line_single_color(&p1, &p2, mlx, color);
	else if (-1.0 <= brs.fslope && brs.fslope <= 1.0 && brs.deltax > 0)
		bresenham_line_degree_315_45(mlx, &brs, color);
	else if ((brs.fslope < -1.0 || 1.0 < brs.fslope) && brs.deltay > 0)
		bresenham_line_degree_45_135(mlx, &brs, color);
	else if (-1.0 <= brs.fslope && brs.fslope <= 1.0 && brs.deltax < 0)
		bresenham_line_degree_135_225(mlx, &brs, color);
	else if ((brs.fslope < -1.0 || 1.0 < brs.fslope) && brs.deltay < 0)
		bresenham_line_degree_225_315(mlx, &brs, color);
}
