/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:06:23 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/23 17:07:18 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len_total;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2);
	errno = 0;
	newstr = malloc(sizeof(char) * (len_total + 1));
	if (newstr == NULL)
		return (NULL);
	newstr[0] = '\0';
	ft_strlcat(newstr, s1, len_total + 1);
	ft_strlcat(newstr, s2, len_total + 1);
	return (newstr);
}

// int main()
// {
// 	char *s1 = "where is my ";
// 	char *s2 = "malloc ???";

// 	printf("%s\n", ft_strjoin(s1, s2));

// }
