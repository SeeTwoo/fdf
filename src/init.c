/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:51:07 by walter            #+#    #+#             */
/*   Updated: 2025/03/18 09:21:43 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	null_all(t_arg *arg)
{
	arg->points = NULL;
	arg->img.img = NULL;
	arg->img.addr = NULL;
	arg->mlx = NULL;
	arg->mlx_win = NULL;
	arg->line = NULL;
}

void	init(t_arg *arg)
{
	null_all(arg);
	arg->mlx = mlx_init();
	if (!arg->mlx)
		error("Cannot allocate memory", arg);
	arg->mlx_win = mlx_new_window(arg->mlx, WIN_W, WIN_H, "fdf");
	if (!arg->mlx_win)
		error("Cannot allocate memory", arg);
	arg->img.img = mlx_new_image(arg->mlx, WIN_W, WIN_H);
	if (!arg->img.img)
		error("Cannot allocate memoory", arg);
	arg->img.addr = mlx_get_data_addr(arg->img.img, &arg->img.bpx,
			&arg->img.ln_len, &arg->img.endn);
}
