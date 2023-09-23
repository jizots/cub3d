/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:50:42 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/23 18:43:25 by sotanaka         ###   ########.fr       */
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
	int	status;

	status = get_map(fd, meta);
	if (status != 0)
		return (status);
	status = verify_map(meta);
	if (status == 0)
		return (0);
	free_map_null_terminated((void ***)&(meta->map));
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
		free_meta(meta);
	close(fd);
	return (status);
}
