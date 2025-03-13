/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:46:19 by walter            #+#    #+#             */
/*   Updated: 2025/03/13 15:54:09 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FUNC_H
# define FDF_FUNC_H

void	init(t_arg *arg);
void	setup_color(t_color *color, t_line *line);
void	setup_line(t_line *line, t_point *start, t_point *finish);
void	draw_line(t_data *img, t_line *line, t_color *color);
void	set_hooks(t_arg *arg);

#endif
