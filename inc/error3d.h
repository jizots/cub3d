/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:12:35 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/20 14:37:58 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR3D_H
# define ERROR3D_H

# include "cub3d.h"

/*-------difine------*/
# define MULTI_P 1
# define NOTHING_P 2
# define UNDEFINED_C 3
# define NO_WALL 4
# define UNEXPETC_COLORCODE 5
# define FAIL_ELEM -6
# define SUCCESS_ELEM 1

/*-------prototype------*/
int		perror_wrap(char *msg, int return_value);
int		error_msg_file(int flag, size_t line);

#endif
