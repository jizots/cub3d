/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ends_with_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:49:51 by hotph             #+#    #+#             */
/*   Updated: 2023/09/24 10:52:33 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft_utils.h"

bool	ends_with_str(const char *str, const char *end)
{
	size_t	str_len;
	size_t	end_len;

	str_len = ft_strlen(str);
	end_len = ft_strlen(end);
	if (str_len < end_len)
		return (false);
	if (ft_strncmp(str + str_len - end_len, end, end_len) == 0)
		return (true);
	return (false);
}
