/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:15:08 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/19 14:08:13 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error3d.h"

int	perror_wrap(char *msg, int return_value)
{
	perror(msg);
	return (return_value);
}

int	error_msg_map(int flag, size_t line)
{
	if (flag == MULTI_P || flag == NOTHING_P)
		printf("Line#%d: Map Error. Set only one personal mark in map\n", line);
	if (flag == UNDEFINED_C)
		printf ("Line#%d: Map Error. You can use only [0][1][N][S][W][E]\n", line);
	if (flag == NO_WALL)
		printf ("Line#%d: Map Error. Map dose not surround by wall\n", line);
	if (flag == UNEXPETC_COLORCODE)
		printf ("Line#%d: COLOR Error. COLOR CODE must set inside 0-255\n", line);
}
