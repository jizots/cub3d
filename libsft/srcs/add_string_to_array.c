/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_string_to_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:11:40 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/20 15:47:23 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft_utils.h"

char	**add_string_to_array(char *src_add, char **old_array)
{
	char	**new_array;
	int		size_alloc;

	if (!src_add)
		return (old_array);
	size_alloc = count_row_of_matrix(old_array) + 2;
	new_array = malloc(sizeof(char *) * size_alloc);
	if (new_array == NULL)
		return (NULL);
	ft_memcpy(new_array, old_array, sizeof(char *) * (size_alloc - 1));
	new_array[size_alloc - 2] = src_add;
	new_array[size_alloc - 1] = NULL;
	free(old_array);
	return (new_array);
}
