/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:27:40 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/05 19:00:21 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	double	n = -25.45;
	double	new;
	long	binary_shit;
	long	mantissa;
	long	exponent;
	long	sign;	

	binary_shit = *(long *)&n;
	(void)mantissa;
	(void)exponent;
	sign = (binary_shit >> 63 & 1);
	new = *(double *)&binary_shit;
	printf("%d\n", sign);
	printf("%f\n", new);
	return (0);
}
