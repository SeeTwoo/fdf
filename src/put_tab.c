/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:21 by wbeschon          #+#    #+#             */
/*   Updated: 2025/02/06 16:21:18 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_tab(t_fdf_point ***tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			printf("(%d,%d)(%d, %d)\t\t", tab[i][j]->x, tab[i][j]->y, tab[i][j]->screen_x, tab[i][j]->screen_y);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
	return (1);
}
void	pix_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || x > 999 || y < 0 || y > 799)
		return ;
	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

void	put_tab(t_fdf_point ***tab, t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j + 1])
				draw_line(img, tab[i][j], tab[i][j + 1]);
			if (tab[i + 1])
				draw_line(img, tab[i][j], tab[i + 1][j]);
			j++;
		}
		i++;
	}
}
