/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:04:04 by sotanaka          #+#    #+#             */
/*   Updated: 2023/08/25 16:07:22 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	if (n == 0)
		return (0);
	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	i = 0;
	while (i < n && c1[i] == c2[i])
		i++;
	if (i == n)
		return (0);
	return (c1[i] - c2[i]);
}

// int main()
// {
//     char    str1[]=".........\0a";
//     char    str2[]=".........\0b";
// 	int i=10;
//     int j=11;

//     printf("%d %d\n",memcmp(str1, str2, 0), ft_memcmp(str1, str2, 0));
//     printf("%d %d\n",memcmp(str1, str2, i), ft_memcmp(str1, str2, i));
//     printf("%d %d\n",memcmp(str1, str2, j), ft_memcmp(str1, str2, j));
// }
