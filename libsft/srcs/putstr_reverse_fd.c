/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_reverse_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:32:47 by sotanaka          #+#    #+#             */
/*   Updated: 2023/09/29 09:48:25 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft_utils.h"

int	putstr_reverse_fd(char *s, int fd)
{
	int	len;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	while (len)
	{
		if (write (fd, &s[--len], 1) == -1)
			return (-1);
	}
	return (0);
}

// int main()
// {
// 	int fd;
// 	fd = open("inputfile", O_WRONLY);
// 	if (fd == -1)
// 		puts("error");
// 	ft_putstr_fd("42 Tokyo", fd);
// 	close(fd);
// }
