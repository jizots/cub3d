/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:07:19 by sotanaka          #+#    #+#             */
/*   Updated: 2023/08/16 09:30:21 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

// char    ft_totest(unsigned int num, char c)
// {
//     printf("%u\n", num);
//     if (97 <= c && c <= 122)
//         return (c - 32);
//     return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	if (s == NULL || f == NULL)
		return (NULL);
	newstr = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

// int main()
// {
//     char    str[] = "qwertyuiop";

//     printf("%s", ft_strmapi(str, ft_totest));
// }
