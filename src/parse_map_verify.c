/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_verify.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:06:52 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/21 19:09:23 by sotanaka         ###   ########.fr       */
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

//Fail condition: Place in {WHITE_SPACE} or {x <= 0} or {strlen() - 1 <= x}
//	or {y <= 0} or {(row_size - 1) <= y}
//Can move condition: Next indent is {not y <= 0 or y >= (rowsize - 1)} and
//	{not x <= 0 or x >= strlen(x)} and {map(next) == '0'}
//Fill VISITED condition: Afer moved. Not much fail condition.
//Success condition: surrounded by {v} or {1} or {HUMAN}
//Other: Fail
int	is_map_surrounded_by_wall(char **map, size_t rowsize, int x, int y)
{
	if (x <= 0 || y <= 0 || (ft_strlen(map[y - 1])) <= x
		|| (rowsize - 1) <= y)//Place at fail. もしかしたら、現在の場所の値のレビューを追加するかも。
		return (ERROR);
	if (map[y][x] == '0')
		map[y][x] = VISITED;
	if (0 < y && ft_strlen(map[y - 1]) >= x && map[y - 1][x] == '0')//Can Up
	{
		if (is_map_surrounded_by_wall(map, rowsize, x, y - 1) == ERROR)
			return (ERROR);
	}
	if (ft_strlen(map[y]) >= x + 1 && map[y][x + 1] == '0')//Can right
	{
		if (is_map_surrounded_by_wall(map, rowsize, x + 1, y) == ERROR)
			return (ERROR);
	}
	if (y < rowsize - 1 && ft_strlen(map[y + 1]) >= x && map[y + 1][x] == '0')//Can down
	{
		if (is_map_surrounded_by_wall(map, rowsize, x, y + 1) == ERROR)
			return (ERROR);
	}
	if (0 < x && map[y][x - 1] == '0')//Can left
	{
		if (is_map_surrounded_by_wall(map, rowsize, x - 1, y) == ERROR)
			return (ERROR);
	}
	// if (ft_strchr("v1NWSE", map[y - 1][x]) && ft_strchr("v1NWSE", map[y][x + 1])
	// 	&& ft_strchr("v1NWSE", map[y + 1][x]) && ft_strchr("v1NWSE", map[y][x - 1]))//success
	// 	return (true);
	return (VALID);
}

int	verify_map(t_meta *meta)
{
	int		status;

	status = verify_appeared_char(meta->map, &(meta->human));
	if (status != 0)
		return (error_msg_file(status, 9999));
	if (is_map_surrounded_by_wall(meta->map, count_row_of_matrix(meta->map), 
		(int)meta->human.point2d.x, (int)meta->human.point2d.y) == ERROR)
		return (error_msg_file(NO_WALL, 9999));
	return (0);
}
