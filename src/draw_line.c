/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:28:59 by walter            #+#    #+#             */
/*   Updated: 2025/03/13 19:51:24 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_color(t_color *color, t_line *line)
{
	color->r1 = (line->color_start >> 16) & 0xFF;
	color->g1 = (line->color_start >> 8) & 0xFF;
	color->b1 = line->color_start & 0xFF;
	color->r2 = (line->color_finish >> 16) & 0xFF;
	color->g2 = (line->color_finish >> 8) & 0xFF;
	color->b2 = line->color_finish & 0xFF;
}

void	setup_line(t_line *line, t_point *start, t_point *finish)
{
	line->x_start = start->x_2d;
	line->y_start = start->y_2d;
	line->x_finish = finish->x_2d;
	line->y_finish = finish->y_2d;
	line->color_start = start->color;
	line->color_finish = finish->color;
	line->dx = abs(line->x_finish - line->x_start);
	line->dy = abs(line->y_finish - line->y_start);
	if (line->x_start < line->x_finish)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->y_start < line->y_finish)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
	if (line->dy > line->dx)
		line->length = line->dx;
	else
		line->length = line->dy;
}

int	interpolate_color(t_color *color, float t)
{
	int	r;
	int	g;
	int	b;

	r = color->r1 + (int)(t * (color->r2 - color->r1));
	g = color->g1 + (int)(t * (color->g2 - color->g1));
	b = color->b1 + (int)(t * (color->b2 - color->b1));
	return ((r << 16) | (g << 8) | b);
}

void	pix_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->ln_len + x * (data->bpx / 8));
	*(unsigned int *)dest = color;
}

void	draw_line(t_data *img, t_line *line, t_color *color)
{
	int		point_color;

	line->step = 0;
	while (line->x_start != line->x_finish && line->y_start != line->y_finish)
	{
		line->t = 0;
		if (line->length != 0)
			line->t = (float)line->step / line->length;
		printf("t = %f\n", line->t);
		point_color = interpolate_color(color, line->t);
		pix_put(img, line->x_start, line->y_start, point_color);
		line->e2 = 2 * line->err;
		if (line->e2 > -line->dy)
		{
			line->err -= line->dy;
			line->x_start += line->sx;
		}
		if (line->e2 < line->dx)
		{
			line->err += line->dx;
			line->y_start += line->sy;
		}
		line->step++;
	}
}
