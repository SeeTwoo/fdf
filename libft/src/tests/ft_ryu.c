/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ryu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:56:01 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/06 14:53:49 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

typedef struct s_number	t_number;

struct s_number
{
	double	number;
	long	binary;
	long	sign;
	long	exponent;
	long	significand;
};

void	extract(t_number *number)
{
	number->binary = *(long *)&number->number;
	number->sign = (number->binary << 1) & 1;
	number->exponent = (number->binary >> 52 & ((1L << 11) - 1)) - 1023;
	number->significand = number->binary & (1L << 52) - 1;
}

void	rebuild(t_number *number)
{
	double	new;
	double	real_signif;

	real_signif = 1 + (number->significand / pow(2, 52));
	new = pow(-1, number->sign) * real_signif * pow(2, number->exponent);
	printf("rebuilt number is: %f\n", new);
}

int	main(void)
{
	int			iter;

	iter = 2000000000;
	while (--iter)
		race_extract(25.45);
	return (0);
}
