/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:51:07 by walter            #+#    #+#             */
/*   Updated: 2025/03/15 14:09:20 by walter           ###   ########.fr       */
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
	char	*temp;

	null_all(arg);
	arg->points = NULL;
	arg->mlx = mlx_init();
	arg->mlx_win = mlx_new_window(arg->mlx, WIN_W, WIN_H, "fdf");
	arg->img.img = mlx_new_image(arg->mlx, WIN_W, WIN_H);
	temp = mlx_get_data_addr(arg->img.img, &arg->img.bpx,
			&arg->img.ln_len, &arg->img.endn);
	arg->img.addr = temp;
}
