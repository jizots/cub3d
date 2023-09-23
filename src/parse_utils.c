/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:14:42 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/23 18:29:22 by sotanaka         ###   ########.fr       */
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

printf("path: %s\n", path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror_wrap(path, PATH_ERROR));
	close(fd);
	return (0);
}
