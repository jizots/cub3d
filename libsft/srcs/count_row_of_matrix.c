/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_row_of_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:53:58 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/08 11:48:28 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft_utils.h"

size_t	count_row_of_matrix(char **matrix)
{
	size_t	i;

	if (matrix == NULL)
		return (0);
	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
