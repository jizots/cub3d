/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:14:42 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/21 12:47:21 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_map(int fd, t_meta *meta)
{
	char	*line;
	char	**tmp_map;

	while (1)
	{
		line = ft_gnl(fd);
		if (line == NULL)
			break ;
		if (is_string_composedof(line, WHITE_SPACE) == false)
		{
			tmp_map = add_string_to_array(line, meta->map);
			if (tmp_map == NULL)
			{
				free_map_null_terminated((void ***)&(meta->map));
				return (perror_wrap("parse_map: ", 1));
			}
			meta->map = tmp_map;
		}
		else
			free(line);
	}
	if (meta->map == NULL)
		return (printf("Error. No map data\n"));
	return (0);
}

int	try_open_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror_wrap(path, PATH_ERROR));
	close(fd);
	return (0);
}

int	init_texture(t_meta *meta)
{
	if (my_mlx_xpm_file(&(meta->mlx), &(meta->north_tex)) != 0)
		return (1);
	if (my_mlx_xpm_file(&(meta->mlx), &(meta->south_tex)) != 0)
		return (1);
	if (my_mlx_xpm_file(&(meta->mlx), &(meta->west_tex)) != 0)
		return (1);
	if (my_mlx_xpm_file(&(meta->mlx), &(meta->east_tex)) != 0)
		return (1);
	return (0);
}

int	get_best_row_size(char **map)
{
	int		i;
	int		max;
	int		tmp;

	i = 0;
	max = 0;
	while (map[i] != NULL)
	{
		tmp = ft_strlen(map[i]);
		if (map[i][tmp - 1] == '\n')
		{
			map[i][tmp - 1] = '\0';
			tmp--;
		}
		if (max < tmp)
			max = tmp;
		i++;
	}
	return (max);
}

void	set_human_vector(char **map, t_human *human)
{
	if (map[(int)(human->point.y)][(int)(human->point.x)] == 'E')
		human->vector = get_radian(0);
	else if (map[(int)(human->point.y)][(int)(human->point.x)] == 'S')
		human->vector = get_radian(90);
	else if (map[(int)(human->point.y)][(int)(human->point.x)] == 'W')
		human->vector = get_radian(180);
	else if (map[(int)(human->point.y)][(int)(human->point.x)] == 'N')
		human->vector = get_radian(270);
}
