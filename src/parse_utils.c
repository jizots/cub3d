/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:14:42 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/30 14:46:24 by hotph            ###   ########.fr       */
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
	meta->north_tex.img = mlx_png_file_to_image(
			meta->mlx.mlx, meta->north_tex.filepath,
			&(meta->north_tex.img_width), &(meta->north_tex.img_height));
	meta->south_tex.img = mlx_png_file_to_image(
			meta->mlx.mlx, meta->south_tex.filepath,
			&(meta->south_tex.img_width), &(meta->south_tex.img_height));
	meta->west_tex.img = mlx_png_file_to_image(
			meta->mlx.mlx, meta->west_tex.filepath,
			&(meta->west_tex.img_width), &(meta->west_tex.img_height));
	meta->east_tex.img = mlx_png_file_to_image(
			meta->mlx.mlx, meta->east_tex.filepath,
			&(meta->east_tex.img_width), &(meta->east_tex.img_height));
	if (meta->north_tex.img == NULL || meta->south_tex.img == NULL
		|| meta->west_tex.img == NULL || meta->east_tex.img == NULL)
		return (printf("Error.\nat mlx_png_file_to_image\n"));
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
