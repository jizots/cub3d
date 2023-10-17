/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:05:56 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/11 11:00:01 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

char	*ft_strdup(const char *s)
{
	if (s == NULL)
		return (NULL);
	return (ft_substr(s, 0, ft_strlen(s)));
}

// int main()
// {
//     char    str1[]="";

//    	printf("%s\n",ft_strdup(str1));
//    	printf("%s\n",strdup(str1));
// }
