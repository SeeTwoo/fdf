/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:21 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/18 15:31:34 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_point_lines(t_arg *arg, int i, int j)
{
	t_color	color;
	t_line	line;

	if (arg->points[i][j + 1])
	{
		setup_line(&line, arg->points[i][j], arg->points[i][j + 1]);
		setup_color(&color, &line);
		draw_line(&arg->img, &line, &color);
	}
	if (arg->points[i + 1])
	{
		setup_line(&line, arg->points[i][j], arg->points[i + 1][j]);
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
			draw_point_lines(arg, i, j);
			j++;
		}
		i++;
	}
}
