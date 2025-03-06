/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:51:04 by wbeschon          #+#    #+#             */
/*   Updated: 2025/02/04 14:15:58 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_point(t_fdf_point *point, int scale)
{
	float	x;
	float	y;

	x = (((0.866 * point->x) + (0.866 * point->y)) * scale) + 500;
	y = (((-0.5f * point->x) + (0.5f * point->y) + point->altitude) * scale) + 400;
	point->screen_x = (int)x; 
	point->screen_y = (int)y;
}

void	get_2d_coor(t_fdf_point ***file_points)
{
	int	i;
	int	j;
	int	scale;

	scale = -400 / ((0.866 * file_points[0][0]->x) + (0.866 * file_points[0][0]->y));
	i = 0;
	while (file_points[i])
	{
		j = 0;
		while (file_points[i][j])
		{
			compute_point(file_points[i][j], scale);
			j++;
		}
		i++;
	}
}
