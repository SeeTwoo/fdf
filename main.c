/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:02:43 by wbeschon          #+#    #+#             */
/*   Updated: 2025/02/06 15:43:14 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf_point	***file_points;
	t_data		img;
	void		*mlx;
	void		*mlx_win;

	if (ac != 2)
		return (0);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 800, "fdf");
	printf("init window\n");
	img.img = mlx_new_image(mlx, 1000, 800);
	printf("init image\n");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	file_points = parsing(av[1]);
	if (!file_points)
		return (0);
	printf("parsing file\n");
	get_2d_coor(file_points);
	printf("computing points\n");
//	print_tab(file_points);
	put_tab(file_points, &img); 
	printf("building image\n");
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	printf("pushing image\n");
	mlx_loop(mlx);
	free_file_points(file_points);
	return (0);
}
