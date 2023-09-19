/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:15:08 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/19 18:30:19 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error3d.h"

int	perror_wrap(char *msg, int return_value)
{
	printf("Error\n");
	perror(msg);
	return (return_value);
}

int	error_msg_file(int flag, size_t line)
{
	printf("Error\n");
	if (flag == MULTI_P || flag == NOTHING_P)
		printf("Line#%d: Set only one person mark in map\n", line);
	if (flag == UNDEFINED_C)
		printf ("Line#%d: You can use only [0][1][N][S][W][E]\n", line);
	if (flag == NO_WALL)
		printf ("Line#%d: Map dose not surround by wall\n", line);
	if (flag == UNEXPETC_COLORCODE)
		printf ("Line#%d: COLOR CODE must set inside 0-255\n", line);
	
}
