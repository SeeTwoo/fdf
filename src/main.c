/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:48:42 by walter            #+#    #+#             */
/*   Updated: 2025/03/15 01:52:16 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage(int ac)
{
	if (ac == 2)
		return ;
	ft_error_msg("usage", "./fdf <file>");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_arg	arg;

	usage(ac);
	init(&arg);
	check_file(&arg, av[1]);
	parsing(&arg, av[1]);
	get_2d_coor(arg.points);
	build_image(&arg);
	mlx_put_image_to_window(arg.mlx, arg.mlx_win, arg.img.img, 0, 0);
	set_hooks(&arg);
	mlx_loop(arg.mlx);
}
