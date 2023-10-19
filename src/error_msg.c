/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:15:08 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/19 14:22:04 by sotanaka         ###   ########.fr       */
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
	if (flag == PERSON_ERROR)
		printf("Line#%zu: Set\033[31m only or at-least \
one person mark\033[0m in map\n", line);
	else if (flag == UNDEFINED_C)
		printf ("Line#%zu: You can\033[31m use only \
[0][1][N][S][W][E]\033[0m\n", line);
	else if (flag == NO_WALL)
		printf ("Line#%zu:\033[31m Map dose not surround by wall\033[0m\n", line);
	else if (flag == UNEXPETC_COLORCODE)
		printf ("Line#%zu:\033[31m COLOR CODE must set \
inside 0-255\033[0m\n", line);
	else if (flag == FILENAME_ERROR)
		printf("Line#%zu: Invalid file name\n", line);
	else if (flag == FAIL_ELEM)
		printf("Line#%zu: Invalid element\n", line);
	else if (flag == MAP_ERROR)
		printf("Line#%zu:\033[31m MAP is too big\033[0m \
change within WIDTH: %d, HIGHT: %d\n", line, MAP_WIDTH / 3, MAP_HEIGHT / 3);
	return (flag);
}
