/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:12:35 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/24 11:29:32 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR3D_H
# define ERROR3D_H

# include "cub3d.h"

/*-------difine------*/
# define PERSON_ERROR 1
# define UNDEFINED_C 2
# define NO_WALL 3
# define UNEXPETC_COLORCODE 4
# define PATH_ERROR 5
# define FILENAME_ERROR 6
# define FAIL_ELEM -6
# define SUCCESS_ELEM 1

/*-------prototype------*/
int		perror_wrap(char *msg, int return_value);
int		error_msg_file(int flag, size_t line);

#endif
