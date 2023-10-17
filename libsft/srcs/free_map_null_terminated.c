/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_null_terminated.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:24:56 by hotph             #+#    #+#             */
/*   Updated: 2023/09/21 11:19:52 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft_utils.h"

/*Free map of null terminated.*/
void	free_map_null_terminated(void ***map)
{
	size_t	i;

	if (*map == NULL)
		return ;
	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}
