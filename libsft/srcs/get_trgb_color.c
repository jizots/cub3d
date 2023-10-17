/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_trgb_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:29:19 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/08 11:46:58 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft.h"

static unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

static unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

static unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

static unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

uint8_t	*get_trgb_color(int color, unsigned char *div_color)
{
	div_color[0] = get_t(color);
	div_color[1] = get_r(color);
	div_color[2] = get_g(color);
	div_color[3] = get_b(color);
	return (div_color);
}
