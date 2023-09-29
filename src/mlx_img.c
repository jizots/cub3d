/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:50:06 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/29 10:12:44 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"
#include "error3d.h"

int	my_mlx_create_image_addr(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (mlx->img == NULL)
		return (perror_wrap("Error. at mlx_new_img", 1));
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
			&(mlx->line_length), &(mlx->endian));
	if (mlx->addr == NULL)
		return (perror_wrap("Error. at mlx_get_data_addr", 1));
	return (0);
}

void	my_mlx_image_clear(t_mlx *mlx)
{
	ft_bzero(mlx->addr,
		SCREEN_HEIGHT * SCREEN_WIDTH * (mlx->bits_per_pixel / 8));
}
