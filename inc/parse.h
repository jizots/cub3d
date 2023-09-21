/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:28:27 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/21 18:58:07 by sotanaka         ###   ########.fr       */
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
# define ERROR 1
# define CONTINUE 2
# define VALID 3

/*------typedef------*/

/*------prototype------*/
int		parse_line_element(char *str, t_meta *meta, size_t line_num, int flag);
int		verify_map(t_meta *meta);

#endif