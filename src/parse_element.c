/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:45:32 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/10 08:59:33 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	color_duplication_check(t_meta *meta)
{
	if (meta->floor_color == -1 || meta->ceiling_color == -1)
		return (error_msg_file(FAIL_ELEM, 0));
	if (WALL_COLOR == meta->floor_color || WALL_COLOR == meta->ceiling_color)
		return (error_msg_file(FAIL_ELEM, 0));
	return (0);
}

static int	copy_path_of_texture(char **split, t_meta *meta)
{
	if (count_row_of_matrix(split) != 2)
		return (FAIL_ELEM);
	if (ft_memcmp(split[0], "NO", 3) == 0)
		meta->north_tex.filepath = ft_strdup(split[1]);
	else if (ft_memcmp(split[0], "SO", 3) == 0)
		meta->south_tex.filepath = ft_strdup(split[1]);
	else if (ft_memcmp(split[0], "WE", 3) == 0)
		meta->west_tex.filepath = ft_strdup(split[1]);
	else if (ft_memcmp(split[0], "EA", 3) == 0)
		meta->east_tex.filepath = ft_strdup(split[1]);
	else
		return (FAIL_ELEM);
	if (try_open_path(split[1]) != 0)
		return (FAIL_ELEM);
	return (0);
}

static int	get_rgb(int *rgb, char **split, int flag)
{
	char	**rgb_char;
	int		i;
	int		status;

	rgb_char = split_multichar(split[1], ", \t");
	if (rgb_char == NULL)
		return (perror_wrap("split", FAIL_ELEM));
	status = 0;
	if (count_row_of_matrix(rgb_char) != 3)
		status = FAIL_ELEM;
	i = 0;
	while (status != FAIL_ELEM && i < 3)
	{
		rgb[i] = ft_atoi(rgb_char[i]);
		if (rgb[i] < 0 || 255 < rgb[i])
		{
			status = error_msg_file(UNEXPETC_COLORCODE, flag);
			break ;
		}
		i++;
	}
	free_map_null_terminated((void ***)&rgb_char);
	return (status);
}

static int	parse_color(char **split, t_meta *meta, int flag)
{
	int		rgb[3];
	int		status;

	if (count_row_of_matrix(split) != 2)
		return (FAIL_ELEM);
	status = get_rgb(rgb, split, flag);
	if (status != 0)
		return (status);
	if (ft_memcmp(split[0], "F", 2) == 0)
		meta->floor_color = create_trgb_color(0, rgb[0], rgb[1], rgb[2]);
	else if (ft_memcmp(split[0], "C", 2) == 0)
		meta->ceiling_color = create_trgb_color(0, rgb[0], rgb[1], rgb[2]);
	else
		return (FAIL_ELEM);
	return (0);
}

int	parse_line_element(char *str, t_meta *meta, size_t line_num, int flag)
{
	char	**split;
	int		status;

	if (is_string_composedof(str, WHITE_SPACE) == true)
		return (IGNORE_LINE);
	split = split_multichar(str, WHITE_SPACE);
	if (split == NULL)
		return (perror_wrap("split: ", FAIL_ELEM));
	status = 0;
	if (flag < 4)
		status = copy_path_of_texture(split, meta);
	else
		status = parse_color(split, meta, flag);
	free_map_null_terminated((void ***)&split);
	if (status == FAIL_ELEM)
		return (error_msg_file(FAIL_ELEM, line_num));
	else if (status == UNEXPETC_COLORCODE)
		return (FAIL_ELEM);
	return (SUCCESS_ELEM);
}
