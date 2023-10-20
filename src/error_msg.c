/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:15:08 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/19 19:49:02 by sotanaka         ###   ########.fr       */
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
		printf("Set\033[31m only or at-least one person mark\033[0m in map\n");
	else if (flag == UNDEFINED_C)
		printf ("You can\033[31m use only [0][1][N][S][W][E]\033[0m\n");
	else if (flag == NO_WALL)
		printf ("\033[31m Map dose not surround by wall\033[0m\n");
	else if (flag == UNEXPETC_COLORCODE)
		printf ("\033[31m COLOR CODE must set inside 0-255\033[0m\n");
	else if (flag == FILENAME_ERROR)
		printf("Invalid file name\n");
	else if (flag == FAIL_ELEM)
		printf("Line#%zu: Invalid element\n", line);
	else if (flag == MAP_ERROR)
		printf("\033[31m MAP is too big\033[0m \
change within WIDTH: %d, HIGHT: %d\n", MAP_WIDTH / 3, MAP_HEIGHT / 3);
	return (flag);
}
