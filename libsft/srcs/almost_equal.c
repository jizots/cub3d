/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almost_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:01:12 by hotph             #+#    #+#             */
/*   Updated: 2023/10/08 11:48:48 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft_utils.h"

bool	almost_equal_double(double a, double b)
{
	double	epsilon;

	epsilon = 0.00001;
	if (fabs(a - b) < epsilon)
		return (true);
	return (false);
}
