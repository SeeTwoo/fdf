/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2d_coor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:28:22 by wbeschon          #+#    #+#             */
/*   Updated: 2025/01/28 11:32:26 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	x;
	int y;
	int	z;
	float	screen_x;
	float	screen_y;

	if (ac != 4)
		return (0);
	x = atoi(av[1]);
	y = atoi(av[2]);
	z = atoi(av[3]);
	screen_x = ((0.866 * x) + (0.866 * y)) * 100;
	screen_y = ((-0.5 * x) + (0.5 * y) + z) * 100;
	printf("x = %f\nand\ny = %f\n", screen_x, screen_y);
	return (0);
}
