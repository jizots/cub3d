/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:08:03 by sotanaka          #+#    #+#             */
/*   Updated: 2023/08/16 09:30:23 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	cc;

	cc = (char) c;
	result = NULL;
	while (*s)
	{
		if (*s == cc)
			result = (char *) s;
		s += 1;
	}
	if (cc == '\0')
		return ((char *) s);
	return (result);
}

// int main(void)
// {
//     char str[] = "woi;egn;iener32r4";
//     char c = 'e'; // check \0
//
//     printf("std %s\nmy  %s", strrchr(str, c), ft_strrchr(str, c));
//     return (0);
// }
