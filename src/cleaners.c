/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:50:27 by walter            #+#    #+#             */
/*   Updated: 2025/03/15 13:38:11 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_point_array(t_point **points)
{
	int	i;

	i = 0;
	if (!points)
		return ;
	while (points[i])
	{
		free(points[i]);
		i++;
	}
	free(points);
}

void	free_triple_array(t_point ***points)
{
	int	i;

	i = 0;
	if (!points)
		return ;
	while (points[i])
	{
		free_point_array(points[i]);
		i++;
	}
	free(points);
}

void	error(char *msg, t_arg *arg)
{
	ft_error_msg(msg, NULL);
	free(arg->line);
	free_triple_array(arg->points);
	(void)arg;
	exit(EXIT_FAILURE);
}
