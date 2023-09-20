/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:50:42 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/20 14:55:35 by sotanaka         ###   ########.fr       */
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

static int	parse_map(int fd, t_meta *meta)
{
	char	*line;
	int		status;

	status = 0;
	while (1)
	{
		line = ft_gnl(fd);
		if (line == NULL)
			break ;
		status = parse_line_map(line, meta);
		free(line);
	}
	return (status);
}

int	cub3d_parse(char *file, t_meta *meta)
{
	int		fd;
	int		status;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror_wrap("open", 1));
	status = parse_elements(fd, meta);
	if (status == 0);
		status = parse_map(fd, meta);
	close(fd);
	return (status);
}

// int main()
// {
// 	t_meta meta;
// 	cub3d_parse("map/1.cub", &meta);
// 	printf("north: %s\n", meta.north_tex);
// 	printf("south: %s\n", meta.south_tex);
// 	printf("west: %s\n", meta.west_tex);
// 	printf("east: %s\n", meta.east_tex);
// 	printf("floor: %d\n", meta.floor_color);
// 	printf("ceiling: %d\n", meta.ceiling_color);
// 	return (0);
// }