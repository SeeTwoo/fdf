/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:19:05 by walter            #+#    #+#             */
/*   Updated: 2025/03/18 13:41:27 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*keycode i = 99 and o = 114
          u = 103 and d = 101*/

void	zoom(int keycode, t_arg *arg)
{
	float	inc;

	if (keycode == 99)
		inc = 0.25f;
	else if (arg->zoom <= 0.25f)
		return ;
	else
		inc = -0.25f;
	mlx_destroy_image(arg->mlx, arg->img.img);
	arg->img.img = mlx_new_image(arg->mlx, WIN_W, WIN_H);
	if (!arg->img.img)
		error("Cannot allocate memory", arg);
	arg->zoom += inc;
	get_2d_coor(arg->points, arg->zoom);
	build_image(arg);
	//mlx_clear_window(arg->mlx, arg->mlx_win);
	mlx_put_image_to_window(arg->mlx, arg->mlx_win, arg->img.img, 0, 0);
}

int	ft_button(int keycode, t_arg *arg)
{
	if (keycode == 99 || keycode == 114)
		zoom(keycode, arg);
	if (keycode != ESC_CODE)
		return (0);
	mlx_destroy_image(arg->mlx, arg->img.img);
	mlx_destroy_window(arg->mlx, arg->mlx_win);
	mlx_destroy_display(arg->mlx);
	free(arg->mlx);
	free_triple_array(arg->points);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_mouse(t_arg *arg)
{
	mlx_destroy_image(arg->mlx, arg->img.img);
	mlx_destroy_window(arg->mlx, arg->mlx_win);
	mlx_destroy_display(arg->mlx);
	free(arg->mlx);
	free_triple_array(arg->points);
	exit(EXIT_SUCCESS);
	return (0);
}

void	set_hooks(t_arg *arg)
{
	mlx_hook(arg->mlx_win, 2, 1, ft_button, arg);
	mlx_hook(arg->mlx_win, 17, 0, ft_mouse, arg);
}
