/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:51:07 by walter            #+#    #+#             */
/*   Updated: 2025/03/13 16:05:04 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_arg *arg)
{
	char	*temp;

	arg->mlx = mlx_init();
	arg->mlx_win = mlx_new_window(arg->mlx, WIN_W, WIN_H, "fdf");
	arg->img.img = mlx_new_image(arg->mlx, WIN_W, WIN_H);
	temp = mlx_get_data_addr(arg->img.img, &arg->img.bpx, &arg->img.ln_len, &arg->img.endn);
	arg->img.addr = temp;
}
