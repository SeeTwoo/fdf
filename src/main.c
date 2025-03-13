/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:48:42 by walter            #+#    #+#             */
/*   Updated: 2025/03/13 18:59:21 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage(int ac)
{
	if (ac == 5)
		return ;
	ft_error_msg("usage", "./fdf <file>");
	exit(EXIT_FAILURE);
}

void	mini_parsing(t_point *start, t_point *finish, char **av)
{
	start->x_2d = ft_atoi(av[1]);
	start->y_2d = ft_atoi(av[2]);
	start->color = 0xFFFF0000;
	finish->x_2d = ft_atoi(av[3]);
	finish->y_2d = ft_atoi(av[4]);
	finish->color = 0xFF0000FF;
}

int	main(int ac, char **av)
{
	t_arg	arg;
	t_line	line;
	t_color	color;
	t_point	start;
	t_point	finish;

	usage(ac);
	init(&arg);
	mini_parsing(&start, &finish, av);
	setup_line(&line, &start, &finish);
	setup_color(&color, &line);
	draw_line(&arg.img, &line, &color);
	mlx_put_image_to_window(arg.mlx, arg.mlx_win, arg.img.img, 0, 0);
	set_hooks(&arg);
	mlx_loop(arg.mlx);
}
