/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_which_direction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:59:27 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/08 11:48:40 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft_utils.h"

bool	is_right_direction(double radian)
{
	if (radian < M_PI / 2 || 3 * (M_PI / 2) < radian)
		return (true);
	return (false);
}

bool	is_up_direction(double radian)
{
	if (M_PI < radian && radian < M_PI * 2)
		return (true);
	return (false);
}

void	set_radian_within_2pi(double *radian)
{
	while (*radian < 0)
		*radian += 2 * M_PI;
	while (*radian >= 2 * M_PI)
		*radian -= 2 * M_PI;
}
