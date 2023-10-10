/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:15:08 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/10 09:40:33 by hotph            ###   ########.fr       */
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
	if (flag == FAIL_ELEM)
		printf("Line#%zu: Invalid element\n", line);
	return (flag);
}
