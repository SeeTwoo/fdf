/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:51:04 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/18 11:29:26 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_point(t_point *point, float scale)
{
	float	x_2d;
	float	y_2d;
	float	x;
	float	y;
	float	z;

	x = (float)point->x;
	y = (float)point->y;
	z = (float)point->z;
	x_2d = (((x - y) * cos(0.523599)) * scale) + (WIN_W / 2);
	y_2d = ((z * -2.5f + (x + y) * sin(0.523599)) * scale) + (WIN_H / 2);
	point->x_2d = x_2d;
	point->y_2d = y_2d;
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
