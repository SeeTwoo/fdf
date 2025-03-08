/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:56:49 by wbeschon          #+#    #+#             */
/*   Updated: 2025/02/06 16:20:17 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_line(t_line *line, t_fdf_point *a, t_fdf_point *b)
{
	int		x_line;
	int		y_line;

	x_line = b->screen_x - a->screen_x;
	y_line = b->screen_y - a->screen_y;
	if ((abs(x_line) > abs(y_line)  && a->screen_x < b->screen_x) 
	|| (abs(y_line) > abs(x_line) && a->screen_y < b->screen_y))
	{
		line->start_x = a->screen_x;
		line->start_y = a->screen_y;
		line->end_x = b->screen_x;
		line->end_y = b->screen_y;
	}
	else if ((abs(x_line) > abs(y_line) && b->screen_x < a->screen_x) 
	|| (abs(y_line) > abs(x_line) && b->screen_y < a->screen_y))
	{
		line->start_x = b->screen_x;
		line->start_y = b->screen_y;
		line->end_x = a->screen_x;
		line->end_y = a->screen_y;
	}
	line->x_offset = line->end_x - line->start_x;
	line->y_offset = line->end_y - line->start_y;
}

void	vertical_line(t_line line, t_data *img)
{
	int		y;
	float	x;

	y = 0;
	while (y <= line.y_offset)
	{
		x = ((float)y / (float)line.y_offset) * (float)line.x_offset;
		pix_put(img, line.start_x + ft_round(x), line.start_y + y, 0xffffff);
		y++;
	}
}

void	horizontal_line(t_line line, t_data *img)
{
	int		x;
	float	y;

	x = 0;
	while (x <= line.x_offset)
	{
		y = ((float)x / (float)line.x_offset) * (float)line.y_offset;
		pix_put(img, line.start_x + x, line.start_y + ft_round(y), 0xffffff);
		x++;
	}
}

void	draw_line(t_data *img, t_fdf_point *a, t_fdf_point *b)
{
	t_line	line;

	init_line(&line, a, b);
	if (abs(line.x_offset) > abs(line.y_offset))
		horizontal_line(line, img);
	else
		vertical_line(line, img);
}

/*int	main(void)
{
	float	percent;

	percent = 0.25;
	printf("%x\n", shade(percent));
	return (0);
}
*/
