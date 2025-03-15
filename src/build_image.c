/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:21 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/15 01:24:28 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	point_lines(t_arg *arg, int i, int j)
{
	t_color	color;
	t_line	line;

	if (arg->points[i][j + 1])
	{
		setup_line(&line, arg->points[i][j], arg->points[i][j + 1]);
		setup_color(&color, &line);
		draw_line(&arg->img, &line, &color);
	}
	if (arg->points[i + 1][j])
	{
		setup_line(&line, arg->points[i][j], arg->points[i + j][j]);
		setup_color(&color, &line);
		draw_line(&arg->img, &line, &color);
	}
}

void	build_image(t_arg *arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg->points[i])
	{
		j = 0;
		while (arg->points[i][j])
		{
			point_lines(arg, i, j);
			j++;
		}
		i++;
	}
}
