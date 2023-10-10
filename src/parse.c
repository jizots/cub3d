/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:50:42 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/10 09:31:43 by hotph            ###   ########.fr       */
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
			return (printf("Error. Insufficient element\n"));
		line_num++;
		flag += parse_line_element(line, meta, line_num, flag);
		free(line);
		if (flag < 0)
			break ;
	}
	if (flag != 6 || color_duplication_check(meta) != 0)
		return (1);
	if (init_texture(meta) != 0)
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

	if (ends_with_str(file, ".cub") == false)
		return (error_msg_file(FILENAME_ERROR, 0));
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
