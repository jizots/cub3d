/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_verify_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:06:52 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/20 16:57:45 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	verify_appeared_char(char **map)
{
	int		i;
	size_t	count_parson;

	i = 0;
	count_parson = 0;
	while (map[i])
	{
		if (is_string_composedof(map[i], " 01NSEW\n\t") == false)
			return (UNDEFINED_C);
		if (ft_strchr(map[i], 'N') || ft_strchr(map[i], 'S')
			|| ft_strchr(map[i], 'E') || ft_strchr(map[i], 'W'))
			count_parson++;
		i++;
	}
	if (count_parson > 1)
		return (MULTI_P);
	if (count_parson == 0)
		return (NOTHING_P);
	return (0);
}

int	verify_map(char **map)
{
	int	status;

	status = verify_appeared_char(map);
	if (status != 0)
		return (error_msg_file(status, 9999));
	return (0);
}
