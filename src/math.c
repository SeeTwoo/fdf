/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:10:44 by wbeschon          #+#    #+#             */
/*   Updated: 2025/02/03 12:44:17 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int	ft_round(float n)
{
	int		int_part;
	float	decimal_part;

	int_part = (int)n;
	decimal_part = n - int_part;
	if (decimal_part < 0.5)
		return (int_part);
	return (int_part + 1);
}

/*#include <stdio.h>
int	main(void)
{
	float	n = 15.8;

	printf("round = %d\n", ft_round(n));
	return (0);
}
*/
