/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:17:43 by hotph             #+#    #+#             */
/*   Updated: 2023/09/20 16:21:16 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft_utils.h"

bool	is_valid_matrix(int num_of_row, char *matrix[], bool (*f)(const char *))
{
	int	i;

	i = 1;
	while (i < num_of_row)
	{
		if ((f)(matrix[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
