/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:56:05 by walter            #+#    #+#             */
/*   Updated: 2025/03/18 09:17:15 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_token(t_arg *arg, char *token, int i, int j)
{
	int		x;
	int		y;
	int		color;
	char	*temp;

	arg->points[i][j] = malloc(sizeof(t_point));
	if (!arg->points[i][j])
		error("Cannot allocate memory", arg);
	x = -(((arg->ppl -1) * 10) / 2) + (j * 10);
	y = -(((arg->lpc -1) * 10) / 2) + (i * 10);
	arg->points[i][j]->x = x;
	arg->points[i][j]->y = y;
	arg->points[i][j]->z = ft_atoi(token);
	temp = ft_strstr(token, ",0x");
	if (temp)
	{
		capitalize(temp);
		color = ft_atoi_base(temp, BASE);
	}
	else
		color = 0xFFFFFFFF;
	arg->points[i][j]->color = color;
}

void	parse_line(t_arg *arg, int i)
{
	char	*token;
	int		j;

	arg->points[i] = ft_calloc(arg->ppl + 1, sizeof(t_point *));
	if (!arg->points[i])
		error("Cannot allocate memory", arg);
	j = 0;
	token = ft_strtok(arg->line, " ");
	while (token)
	{
		parse_token(arg, token, i, j);
		token = ft_strtok(NULL, " ");
		j++;
	}
}

void	parsing(t_arg *arg, char *file_name)
{
	int		fd;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error(strerror(errno), arg);
	arg->points = ft_calloc(arg->lpc + 1, sizeof(t_point **));
	if (!arg->points)
		error("Cannot allocate memory", arg);
	i = 0;
	while (1)
	{
		arg->line = get_next_line(fd);
		if (!arg->line)
			error("Cannot allocate memory", arg);
		if (!arg->line[0])
			break ;
		parse_line(arg, i);
		free(arg->line);
		i++;
	}
	free(arg->line);
	close(fd);
}
