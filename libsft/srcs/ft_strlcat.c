/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:06:34 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/23 17:12:10 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;

	len_s = ft_strlen(src);
	if (dest == NULL || src == NULL)
		return (size + len_s);
	len_d = ft_strlen(dest);
	if (size <= len_d)
		return (size + len_s);
	while (*dest)
		dest++;
	while (size - len_d - 1)
	{
		*dest++ = *src++;
		size--;
		if (*src == '\0')
			break ;
	}
	*dest = '\0';
	return (len_d + len_s);
}
