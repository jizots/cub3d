/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:15:08 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/20 14:39:28 by sotanaka         ###   ########.fr       */
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
		printf("Line#%zu: Set only one person mark in map\n", line);
	if (flag == UNDEFINED_C)
		printf ("Line#%zu: You can use only [0][1][N][S][W][E]\n", line);
	if (flag == NO_WALL)
		printf ("Line#%zu: Map dose not surround by wall\n", line);
	if (flag == UNEXPETC_COLORCODE)
		printf ("Line#%zu: COLOR CODE must set inside 0-255\n", line);
	if (flag == FAIL_ELEM)
		printf("Line#%zu: Invalid element\n", line);
	return (flag);
}
