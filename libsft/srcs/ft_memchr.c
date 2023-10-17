/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:03:49 by sotanaka          #+#    #+#             */
/*   Updated: 2023/08/25 16:06:07 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	compare;
	size_t			i;

	if (n == 0 || s == NULL)
		return (NULL);
	str = (unsigned char *) s;
	compare = (unsigned char) c;
	i = 0;
	while (i < n && str[i] != compare)
		i++;
	if (i == n)
		return (NULL);
	else
		return ((void *) &str[i]);
}
