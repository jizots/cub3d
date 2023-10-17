/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:07:47 by sotanaka          #+#    #+#             */
/*   Updated: 2023/08/16 09:30:23 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	start;
	size_t	i;

	start = 0;
	if (little[0] == '\0' || little == NULL || big == NULL)
		return ((char *) big);
	while (big[start] != '\0' && start < len)
	{
		i = 0;
		while (little[i] == big[start + i])
		{
			if ((start + i) == len)
				return (NULL);
			i++;
			if (little[i] == '\0')
				return ((char *) &big[start]);
		}
		if (big[start + i] == '\0')
			return (NULL);
		start++;
	}
	return (NULL);
}
