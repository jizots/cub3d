/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:32:12 by hotph             #+#    #+#             */
/*   Updated: 2023/10/08 10:56:34 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "cub3d.h"

t_point2df	get_point2d_wall(
				t_ray *verti, t_ray *horiz, t_meta *meta, double vector_ray);
void		init_ray(
				t_ray *verti, t_ray *horiz, t_meta *meta, double *add_radian);
void		next_vertical_intersec(
				t_point2df start, t_ray *verti, double vector, int tile_size);
void		next_horizontal_intersec(
				t_point2df start, t_ray *horiz, double vector, int tile_size);
void		update_current_point(t_point2df *current, t_point2df *next,
				int *flag_up, int *flag_down);
bool		is_wall(t_point2df point, t_mlx *mlx);
char		which_direction(const t_ray *verti, const double radian);
void		draw_raycast_to_human_vector(t_meta *meta);

#endif