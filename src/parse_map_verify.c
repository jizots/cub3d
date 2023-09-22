/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_verify.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:06:52 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/22 14:05:29 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	verify_appeared_char(char **map, t_map *human)
{
	int		i;
	int		j;
	size_t	count_parson;

	i = 0;
	count_parson = 0;
	while (map[i])
	{
		j = 0;
		if (is_string_composedof(map[i], "01NSEW \n\t") == false)
			return (UNDEFINED_C);
		while (map[i][j])
		{
			if (ft_strchr("NWSE", map[i][j]))
			{
				count_parson++;
				human->point2d.x = j;
				human->point2d.y = i;
			}
			j++;
		}
		i++;
	}
	if (count_parson > 1)
		return (MULTI_P);
	if (count_parson == 0)
		return (NOTHING_P);
	return (0);
}

static bool	is_fail_map(char **map, size_t rowsize, int x, int y)
{
	if (x <= 0 || y <= 0 || (ft_strlen(map[y - 1])) <= x
		|| (rowsize - 1) <= y)//Place at fail.
		return (false);
	if (ft_memchr(" \n\0", map[y - 1][x], 3) || ft_memchr(" \n\0", map[y][x + 1], 3)
		|| ft_memchr(" \n\0", map[y + 1][x], 3) || ft_memchr(" \n\0", map[y][x - 1], 3))
		return (false);
	return (true);
}

bool	is_map_surrounded_by_wall(char **map, size_t rowsize, int x, int y)
{
	if (is_fail_map(map, rowsize, x, y) == false)
		return (false);
	if (map[y][x] == '0')
		map[y][x] = VISITED;
	if (0 < y && ft_strlen(map[y - 1]) >= x && map[y - 1][x] == '0')//Can Up
	{
		if (is_map_surrounded_by_wall(map, rowsize, x, y - 1) == false)
			return (false);
	}
	if (ft_strlen(map[y]) >= x + 1 && map[y][x + 1] == '0')//Can right
	{
		if (is_map_surrounded_by_wall(map, rowsize, x + 1, y) == false)
			return (false);
	}
	if (y < rowsize - 1 && ft_strlen(map[y + 1]) >= x && map[y + 1][x] == '0')//Can down
	{
		if (is_map_surrounded_by_wall(map, rowsize, x, y + 1) == false)
			return (false);
	}
	if (0 < x && map[y][x - 1] == '0')//Can left
	{
		if (is_map_surrounded_by_wall(map, rowsize, x - 1, y) == false)
			return (false);
	}
	return (true);
}

int	verify_map(t_meta *meta)
{
	int		status;

	status = verify_appeared_char(meta->map, &(meta->human));
	if (status != 0)
		return (error_msg_file(status, 9999));
	if (is_map_surrounded_by_wall(meta->map, count_row_of_matrix(meta->map), 
		(int)meta->human.point2d.x, (int)meta->human.point2d.y) == false)
		return (error_msg_file(NO_WALL, 9999));
	return (0);
}
