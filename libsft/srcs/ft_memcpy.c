/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:04:16 by sotanaka          #+#    #+#             */
/*   Updated: 2023/08/16 09:29:43 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;
	size_t			i;

	if (src == NULL && n != 0)
		return (NULL);
	dest_char = (unsigned char *) dest;
	src_char = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}

// int main()
// {
//     char    str1[]="10293jfoefjo";
//     char    str2[]="zxcvbnmasdf";
// 	int i=8;
// 	int j= 0;

//    	printf("%s\n",memcpy(NULL, NULL , 3));//zxc93jfoefjo
//    	printf("%s\n",ft_memcpy(NULL, NULL , 2));//vbjfoefjo
// }
