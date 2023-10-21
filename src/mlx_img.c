/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:50:06 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/21 12:47:03 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"
#include "error3d.h"

int	my_mlx_create_image_addr(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (mlx->img == NULL)
		return (perror_wrap("at mlx_new_img", 1));
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
			&(mlx->line_length), &(mlx->endian));
	if (mlx->addr == NULL)
		return (perror_wrap("at mlx_get_data_addr", 1));
	return (0);
}

void	my_mlx_image_clear(t_mlx *mlx)
{
	ft_bzero(mlx->addr,
		SCREEN_HEIGHT * SCREEN_WIDTH * (mlx->bits_per_pixel / 8));
}

int	my_mlx_png_file(t_mlx *mlx, t_tex *tex)
{
	tex->img = mlx_png_file_to_image(mlx->mlx, tex->filepath,
			&(tex->img_width), &(tex->img_height));
	if (tex->img == NULL)
		return (perror_wrap("at mlx_png_file_to_image", 1));
	tex->addr = mlx_get_data_addr(tex->img, &(tex->bpp),
			&(tex->line_length), &(tex->endian));
	if (tex->addr == NULL)
		return (perror_wrap("at mlx_get_data_addr", 1));
	return (0);
}

int	my_mlx_xpm_file(t_mlx *mlx, t_tex *tex)
{
	tex->img = mlx_xpm_file_to_image(mlx->mlx, tex->filepath,
			&(tex->img_width), &(tex->img_height));
	if (tex->img == NULL)
		return (perror_wrap("at mlx_xpm_file_to_image", 1));
	tex->addr = mlx_get_data_addr(tex->img, &(tex->bpp),
			&(tex->line_length), &(tex->endian));
	if (tex->addr == NULL)
		return (perror_wrap("at mlx_get_data_addr", 1));
	return (0);
}
