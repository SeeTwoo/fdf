/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:51:04 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/15 01:43:37 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_point(t_point *point, int scale)
{
	float	x;
	float	y;

	x = (((0.866 * point->x) + (0.866 * point->y)) * scale) + 500;
	y = (((-0.5f * point->x) + (0.5f * point->y)
				+ point->z) * scale) + 400;
	point->x_2d = (int)x;
	point->y_2d = (int)y;
}

void	get_2d_coor(t_point ***points)
{
	int		i;
	int		j;
	float	scale;

	scale = -400 / ((0.866 * points[0][0]->x) + (0.866 * points[0][0]->y));
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
