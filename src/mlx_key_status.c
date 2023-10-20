/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:45:49 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/20 11:15:06 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycode.h"
#include "my_mlx.h"

bool	is_key_W_pressed(unsigned char press)
{
	static bool	is_pressed;

	if (press == KEY_PRESS)
		is_pressed = true;
	else if (press == KEY_RELEASE)
		is_pressed = false;
	return (is_pressed);
}

bool	is_key_A_pressed(unsigned char press)
{
	static bool	is_pressed;

	if (press == KEY_PRESS)
		is_pressed = true;
	else if (press == KEY_RELEASE)
		is_pressed = false;
	return (is_pressed);
}

bool	is_key_S_pressed(unsigned char press)
{
	static bool	is_pressed;

	if (press == KEY_PRESS)
		is_pressed = true;
	else if (press == KEY_RELEASE)
		is_pressed = false;
	return (is_pressed);
}

bool	is_key_D_pressed(unsigned char press)
{
	static bool	is_pressed;

	if (press == KEY_PRESS)
		is_pressed = true;
	else if (press == KEY_RELEASE)
		is_pressed = false;
	return (is_pressed);
}
