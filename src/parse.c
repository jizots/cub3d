/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:50:42 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/20 16:57:09 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	parse_elements(int fd, t_meta *meta)
{
	char	*line;
	int		flag;
	size_t	line_num;

	line_num = 0;
	flag = 0;
	while (flag < 6)
	{
		line = ft_gnl(fd);
		if (line == NULL)
		{
			printf("Error. Insufficient element\n");
			break ;
		}
		line_num++;
		flag += parse_line_element(line, meta, line_num, flag);
		if (flag < 0)
			break ;
		free(line);
	}
	if (flag != 6)
		return (1);
	return (0);
}

static int	get_map(int fd, t_meta *meta)
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
				free_map_null_terminated((void **)meta->map);
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

static int	parse_map(int fd, t_meta *meta)
{
	int	status;

	status = get_map(fd, meta);
	if (status != 0)
		return (status);
	status = verify_map(meta->map);
	if (status == 0)
		return (0);
	free_map_null_terminated((void **)meta->map);
	return (status);
}

int	cub3d_parse(char *file, t_meta *meta)
{
	int		fd;
	int		status;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror_wrap("open: ", 1));
	status = parse_elements(fd, meta);
	if (status == 0)
		status = parse_map(fd, meta);
	if (status != 0)
	//add free fuction. and modify free function void***
	close(fd);
	return (status);
}

// int main()
// {
// 	t_meta meta;
// 	meta.map = NULL;
// 	cub3d_parse("map/1.cub", &meta);
// 	printf("north: %s\n", meta.north_tex);
// 	printf("south: %s\n", meta.south_tex);
// 	printf("west: %s\n", meta.west_tex);
// 	printf("east: %s\n", meta.east_tex);
// 	printf("floor: %d\n", meta.floor_color);
// 	printf("ceiling: %d\n", meta.ceiling_color);

// 	for (int i = 0; meta.map != NULL && meta.map[i] != NULL; i++)
// 		printf("%s", meta.map[i]);

// 	return (0);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }