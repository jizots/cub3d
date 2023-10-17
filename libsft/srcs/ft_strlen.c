/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:07:03 by sotanaka          #+#    #+#             */
/*   Updated: 2023/08/16 09:30:18 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

// int main()
// {
//     char str[]="";
//
//     if (strlen(str) == ft_strlen(str))
//         puts("success");
//     else
//         puts("fault");
//     return (0);
// }
