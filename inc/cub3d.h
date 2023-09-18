/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:30:22 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/18 18:19:45 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*------include-------*/
/*
open, close, read, write, printf, malloc, free, perror, strerror, exit
• All functions of the math library (-lm man man 3 math)
• All functions of the MinilibX
*/
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include "../../libsft/libsft/includes/libsft.h"

/*-------difine------*/
# define SPACE '0'
# define WALL '1'
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

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

/*------prototype------*/
int		cub3d_parse(char *file_name, t_meta *meta);

#endif
