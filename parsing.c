/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:12:47 by wbeschon          #+#    #+#             */
/*   Updated: 2025/02/06 16:03:25 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		while (*s == ' ' || *s == '\n')
			s++;
		if (*s && !ft_strchr(VALID_CHARS, *s))
			return (-1);
		else if (*s)
			count++;
		while (*s && ft_strchr(VALID_CHARS, *s))
			s++;
	}
	return (count);
}

int	check_file(int fd)
{
	int		line_nbr;
	int		word_count;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	word_count = count_words(line);
	if (word_count == -1)
		return (-1);
	line_nbr = 0;
	while (line[0])
	{
		free(line);
		line = get_next_line(fd);
		if ((line[0] && count_words(line) != word_count) || !line)
			return (-1);
		line_nbr++;
	}
	free(line);
	return (line_nbr);
}

t_fdf_point	*parse_token(char *token, int x, int y)
{
	t_fdf_point	*point;
	
	point = malloc(sizeof(t_fdf_point));
	point->altitude = -ft_atoi(token);
	point->x = x;
	point->y = y;
	point->screen_x = 0;
	point->screen_y = 0;
	return (point);
}

t_fdf_point **parse_line(char *line, int line_nbr, int ppl, int index)
{
	t_fdf_point	**array_line;
	char		*token;
	int			i;
	int			x;
	int			y;

	array_line = malloc(sizeof(t_fdf_point) * (ppl + 1));
	if (!array_line)
		return (NULL);
	i = 0;
	token = ft_strtok(line, " ");
	while (token)
	{
		x = -(((ppl - 1) * 10) / 2) + (i * 10);
		y = -(((line_nbr - 1) * 10) / 2) + (index * 10);
		array_line[i] = parse_token(token, x, y);
		token = ft_strtok(NULL, " ");
		i++;
	}
	array_line[i] = NULL;
	return (array_line);
}

t_fdf_point	***create_points(int fd, int line_nbr)
{
	t_fdf_point	***file_points;
	char		*line;
	int			ppl;
	int			i;

	file_points = malloc(sizeof(t_fdf_point**) * line_nbr + 1);
	if (!file_points)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	ppl = count_words(line);
	i = 0;
	while (line[0])
	{
		file_points[i] = parse_line(line, line_nbr, ppl, i);
		if (!file_points[i])
			return (free_failed_points(file_points, i));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	file_points[i] = NULL;
	free(line);
	return (file_points);
}

t_fdf_point	***parsing(char *file_name)
{
	int			fd;
	int			line_nbr;
	t_fdf_point	***file_points;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line_nbr = check_file(fd);
	if (line_nbr == -1)
		return (NULL);
	close(fd);
	fd = open(file_name, O_RDONLY);
	file_points = create_points(fd, line_nbr);
	if (!file_points)
		return (NULL);
	return (file_points);
}
