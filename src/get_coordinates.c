/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:51:04 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/18 15:40:49 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_point(t_point *point, float scale, t_arg *arg)
{
	float	x_2d;
	float	y_2d;
	float	x;
	float	y;
	float	z;

	x = (float)point->x;
	y = (float)point->y;
	z = (float)point->z;
	x_2d = (((x - y) * cos(0.523599)) * scale * arg->zoom)
		+ (WIN_W / 2) + arg->h_off;
	y_2d = ((z * -5.0f + (x + y) * sin(0.523599)) * scale
			* arg->zoom) + (WIN_H / 2) + arg->v_off;
	point->x_2d = x_2d;
	point->y_2d = y_2d;
}

void	get_2d_coor(t_arg *arg)
{
	int		i;
	int		j;
	float	scale;

	scale = -((WIN_W / 2) - 100) / ((0.866 * arg->points[0][0]->x)
			+ (0.866 * arg->points[0][0]->y));
	i = 0;
	while (arg->points[i])
	{
		j = 0;
		while (arg->points[i][j])
		{
			compute_point(arg->points[i][j], scale, arg);
			j++;
		}
		i++;
	}
}
