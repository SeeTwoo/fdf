/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:54:44 by walter            #+#    #+#             */
/*   Updated: 2025/03/15 12:12:50 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(char *line)
{
	int	count;

	count = 0;
	while (*line)
	{
		line += ft_strspn(line, " \n\t");
		if (*line)
			count++;
		line += ft_strcspn(line, " \n\t");
	}
	return (count);
}

void	check_token(char *token, t_arg *arg)
{
	char	*end;
	long	number;

	if (!ft_isdigit(*token) && *token != '-')
		error("invalid map", arg);
	number = ft_strtol(token, &end, 10);
	if (!ft_strchr(" ,\n\0", *end) || number > 500 || number < -500)
		error("invalid map", arg);
	token += ft_strspn(token, "-0123456789");
	if (!(*token))
		return ;
	if (ft_strncmp(token, ",0x", 3) != 0)
		error("invalid map", arg);
	token += 3;
	if (ft_strlen(token) == 0 || ft_strlen(token) > 8)
		error("invalid map", arg);
	while (*token)
	{
		if (!ft_strchr(BASE, *token))
			error("invalid map", arg);
		token++;
	}
}

void	check_line(t_arg *arg)
{
	char	*token;

	token = ft_strtok(arg->line, " \n\t");
	while (token)
	{
		check_token(token, arg);
		token = ft_strtok(NULL, " \n\t");
	}
}

void	check_file(t_arg *arg, char *file_name)
{
	int		fd;
	int		lpc;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error(strerror(errno), arg);
	lpc = 0;
	while (1)
	{
		arg->line = get_next_line(fd);
		if (!arg->line)
			error("Cannot allocate memory", arg);
		if (!arg->line[0])
			break ;
		if (lpc == 0)
			arg->ppl = count_words(arg->line);
		else
			if (arg->ppl != count_words(arg->line))
				error("uneven map", arg);
		check_line(arg);
		free(arg->line);
		lpc++;
	}
	arg->lpc = lpc;
	close(fd);
}
