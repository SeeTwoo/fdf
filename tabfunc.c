/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:35:19 by wbeschon          #+#    #+#             */
/*   Updated: 2025/01/27 17:31:57 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_point	***free_failed_points(t_fdf_point ***file_points, int i)
{
	while (i >= 0)
	{
		free(file_points[i]);
		i--;
	}
	free(file_points);
	return (NULL);
}


void	free_file_points(t_fdf_point ***file_points)
{
	int	i;
	int j;

	i = 0;
	while (file_points[i])
	{
		j = 0;
		while (file_points[i][j])
		{
			free(file_points[i][j]);
			j++;
		}
		free(file_points[i]);
		i++;
	}
	free(file_points);
}

void	print_points_coordinates(t_fdf_point ***file_points)
{
	int	i;
	int j;

	i = 0;
	while (file_points[i])
	{
		j = 0;
		while (file_points[i][j])
		{
			printf("x = %d,\t y = %d,\t alt = %d\t\t", file_points[i][j]->x,
			file_points[i][j]->y, file_points[i][j]->altitude);
			j++;
		}
		printf("\n\n");
		i++;
	}
}
