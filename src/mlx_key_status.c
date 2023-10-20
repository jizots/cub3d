/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:45:49 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/20 12:27:56 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"
#include "keycode.h"

bool	is_key_any_pressed(unsigned char press, bool *key)
{
	if (press == KEY_PRESS)
		*key = true;
	else if (press == KEY_RELEASE)
		*key = false;
	return (*key);
}
