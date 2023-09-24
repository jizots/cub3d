/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:28:27 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/24 17:24:28 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/*------include-------*/
/*
open, close, read
*/
# include <fcntl.h>
# include <unistd.h>
# include "cub3d.h"

/*-------difine------*/
# define IGNORE_LINE 0
# define VISITED 'v'

/*------typedef------*/

/*------prototype------*/
int		parse_line_element(char *str, t_meta *meta, size_t line_num, int flag);
int		verify_map(t_meta *meta);
int		get_map(int fd, t_meta *meta);
int		try_open_path(char *path);
int		init_texture(t_meta *meta);
int		get_best_row_size(char **map);
void	set_human_vector(char **map, t_human *human);

#endif