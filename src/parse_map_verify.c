/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_verify.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:06:52 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/22 16:35:15 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	set_ret_val(size_t count_person)
{
	if (count_person == 1)
		return (0);
	return (PERSON_ERROR);
}

static int	verify_appeared_char(char **map, t_map *human)
{
	int		i;
	int		j;
	size_t	count_person;

	i = 0;
	count_person = 0;
	while (map[i])
	{
		j = 0;
		if (is_string_composedof(map[i], "01NSEW \n") == false)
			return (UNDEFINED_C);
		while (map[i][j])
		{
			if (ft_strchr("NWSE", map[i][j]))
			{
				count_person++;
				human->point2d.x = j;
				human->point2d.y = i;
			}
			j++;
		}
		i++;
	}
	return (set_ret_val(count_person));
}

static bool	is_valid_position(char **map, size_t rowsize, int x, int y)
{
	if (x <= 0 || y <= 0 || (ft_strlen(map[y - 1])) <= (size_t)x
		|| (rowsize - 1) <= (size_t)y)
		return (false);
	if (ft_memchr(" \n\0", map[y - 1][x], 3)
		|| ft_memchr(" \n\0", map[y][x + 1], 3)
		|| ft_memchr(" \n\0", map[y + 1][x], 3)
		|| ft_memchr(" \n\0", map[y][x - 1], 3))
		return (false);
	return (true);
}

bool	is_map_surrounded_by_wall(char **map, size_t rowsize, int x, int y)
{
	if (is_valid_position(map, rowsize, x, y) == false)
		return (false);
	if (map[y][x] == SPACE)
		map[y][x] = VISITED;
	if (0 < y && ft_strlen(map[y - 1]) >= (size_t)x && map[y - 1][x] == SPACE
		&& is_map_surrounded_by_wall(map, rowsize, x, y - 1) == false)
		return (false);
	if (ft_strlen(map[y]) >= ((size_t)x + 1) && map[y][x + 1] == SPACE
		&& is_map_surrounded_by_wall(map, rowsize, x + 1, y) == false)
		return (false);
	if ((size_t)y < rowsize - 1 && ft_strlen(map[y + 1]) >= (size_t)x
		&& map[y + 1][x] == SPACE
		&& is_map_surrounded_by_wall(map, rowsize, x, y + 1) == false)
		return (false);
	if (0 < x && map[y][x - 1] == SPACE
		&& is_map_surrounded_by_wall(map, rowsize, x - 1, y) == false)
		return (false);
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
