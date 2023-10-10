/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:28:27 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/10 09:08:23 by hotph            ###   ########.fr       */
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
int		color_duplication_check(t_meta *meta);
int		verify_map(t_meta *meta);
int		get_map(int fd, t_meta *meta);
int		try_open_path(char *path);
int		init_texture(t_meta *meta);
int		get_best_row_size(char **map);
void	set_human_vector(char **map, t_human *human);

#endif