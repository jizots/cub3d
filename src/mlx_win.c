/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:52:27 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/22 17:40:52 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_create_new_image(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (mlx->img == NULL)
		return (perror_wrap("Error. at mlx_img", 1));
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
			&(mlx->line_length), &(mlx->endian));
	if (mlx->addr == NULL)
		return (perror_wrap("Error. at mlx_addr", 1));
	return (0);
}

void	ft_mlx_image_clear(t_mlx *mlx)
{
	ft_bzero(mlx->addr,
		SCREEN_WIDTH * SCREEN_HEIGHT * mlx->bits_per_pixel);
	mlx_destroy_image(mlx->mlx, mlx->img);
}

int	ft_mlx_create_win(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (perror_wrap("Error. at mlx_int", 1));
	mlx->win
		= mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3DDD");
	if (mlx->win == NULL)
		return (perror_wrap("Error. at mlx_win", 1));
	return (0);
}

int	ft_mlx_close_win(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}
