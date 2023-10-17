/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:09:02 by sotanaka          #+#    #+#             */
/*   Updated: 2023/08/18 18:05:39 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
		len = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, &s[start], len + 1);
	return (dest);
}
