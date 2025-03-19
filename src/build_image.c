/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:21 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/19 14:50:31 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_visible(t_point *start, t_point *finish)
{
	if (start->x_2d > WIN_W && finish->x_2d > WIN_W)
		return (0);
	if (start->x_2d < 0 && finish->x_2d < 0)
		return (0);
	if (start->y_2d > WIN_H && finish->y_2d > WIN_H)
		return (0);
	if (start->y_2d < 0 && finish->y_2d < 0)
		return (0);
	return (1);
}

void	draw_point_lines(t_arg *arg, int i, int j)
{
	t_color	color;
	t_line	line;

	if (!arg->points[i][j + 1])
		;
	else if (is_visible(arg->points[i][j], arg->points[i][j + 1]) == 1)
	{
		setup_line(&line, arg->points[i][j], arg->points[i][j + 1]);
		setup_color(&color, &line);
		draw_line(&arg->img, &line, &color);
	}
	if (!arg->points[i + 1])
		;
	else if (is_visible(arg->points[i][j], arg->points[i + 1][j]) == 1)
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
