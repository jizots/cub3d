/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:38:34 by hotph             #+#    #+#             */
/*   Updated: 2023/09/13 14:00:27 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsft_utils.h"

int	power_num(int num, int exponents)
{
	int	result;

	if (num == 0)
		return (0);
	result = 1;
	while (exponents)
	{
		result *= num;
		exponents--;
	}
	return (result);
}
