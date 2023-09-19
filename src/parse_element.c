/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:45:32 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/19 19:49:02 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	path_to_texture(char **slpit, t_meta *meta)
{

}

int	parse_line_element(char *str, t_meta *meta, size_t line_num, int flag)
{
	char	**split;
	int		status;

	split = split_multichar(str, " \f\n\r\t\v");
	if (split == NULL)
		return (perror_wrap("split", FAIL_ELEM));
	status = 0;
	if (flag < 4)
		status = path_to_texture(split, meta);
	else
		status = parse_color(split, meta, flag);
	free_map_null_terminated(split);
	
	return (SUCCESS_ELEM);
}
