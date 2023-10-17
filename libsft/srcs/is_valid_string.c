/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:03:19 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/18 15:05:03 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft_utils.h"

bool	is_valid_string(char *str, bool condition(char))
{
	int	i;

	i = 0;
	if (str == NULL || condition == NULL)
		return (false);
	while (str[i])
	{
		if (condition(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
