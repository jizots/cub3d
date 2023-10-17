/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:08:38 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/21 13:50:08 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len_newstr;
	char	*dest;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < end)
		start++;
	while (ft_strchr(set, s1[end - 1]) && start < end)
		end--;
	len_newstr = end - start;
	dest = malloc (sizeof(char) * (len_newstr + 1));
	if (dest == NULL)
		return (dest);
	ft_strlcpy (dest, &s1[start], len_newstr + 1);
	return (dest);
}

// int main()
// {
// 	char src[]=  "612345678906  12345678901235 6";
// 	char set[]= "6 5";
// //
// 	char	*dest = ft_strtrim(src, set);
// 	printf("%s\n", dest);
// 	return (0);
// }
