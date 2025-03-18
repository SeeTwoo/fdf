/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:51:04 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/18 10:38:14 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_point(t_point *point, int scale)
{
	float	x;
	float	y;

	x = (((point->x - point->y) * cos(0.523599)) * scale) + (WIN_W / 2);
	y = ((point->z * -1.0f + (point->x + point->y)
				* sin(0.523599)) * scale) + (WIN_H / 2);
	point->x_2d = (int)x;
	point->y_2d = (int)y;
}

void	get_2d_coor(t_point ***points)
{
	int		i;
	int		j;
	float	scale;

	scale = -((WIN_W / 2) - 100) / ((0.866 * points[0][0]->x) + (0.866 * points[0][0]->y));
	i = 0;
	while (points[i])
	{
		j = 0;
		while (points[i][j])
		{
			compute_point(points[i][j], scale);
			j++;
		}
		i++;
	}
}
