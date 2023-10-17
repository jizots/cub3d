/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:05:20 by sotanaka          #+#    #+#             */
/*   Updated: 2023/08/18 17:38:17 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*origin;

	if (dest == NULL || src == NULL)
		return (dest);
	origin = dest;
	while (*dest != '\0')
		dest += 1;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (origin);
}

// int main()
// {
//     char    str1[]="asdfghjkl";
//     char    dest[60]= "1234567890";
//    	printf("%s\n",ft_strcat(dest, NULL));

//     char    dest2[60]= "1234567890";
//    	printf("%s\n",strcat(dest2, NULL));
// }
