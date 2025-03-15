/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:19:05 by walter            #+#    #+#             */
/*   Updated: 2025/03/15 13:40:09 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_button(int keycode, t_arg *arg)
{
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
