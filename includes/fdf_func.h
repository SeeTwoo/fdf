/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:46:19 by walter            #+#    #+#             */
/*   Updated: 2025/03/15 13:40:48 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FUNC_H
# define FDF_FUNC_H

void	build_image(t_arg *arg);
void	check_file(t_arg *arg, char *file_name);
void	draw_line(t_data *img, t_line *line, t_color *color);
void	error(char *msg, t_arg *arg);
void	free_triple_array(t_point ***tab);
void	get_2d_coor(t_point ***file_points);
void	init(t_arg *arg);
void	parsing(t_arg *arg, char *file_name);
void	setup_color(t_color *color, t_line *line);
void	setup_line(t_line *line, t_point *start, t_point *finish);
void	set_hooks(t_arg *arg);

#endif
