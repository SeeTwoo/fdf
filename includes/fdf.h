/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:35:52 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/08 15:12:22 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# ifndef VALID_CHARS
#  define VALID_CHARS "-0123456789"
# endif

typedef struct s_fdf_point t_fdf_point;
typedef struct s_view_matrix t_view_matrix;
typedef struct s_line t_line;

struct s_fdf_point
{
	int	altitude;
	int	x;
	int	y;
	int	screen_x;
	int	screen_y;
};

struct s_line
{
	int	start_x;
	int	start_y;
	int	end_x;
	int end_y;
	int	x_offset;
	int	y_offset;
};

/*struct t_view_matrix
{
	float	view_matrix[4][4] = {
	{0.8660f, 0.0000f, 0.5000f, 0.0000f},
	{0.2500f, 0.8164f, -0.250f, 0.0000f},
	{0.0000f, 0.0000f, 0.0000f, 1.0000f},
	{0.0000f, 0.0000f, 0.0000f, 1.0000f}}
};
*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

int			abs(int n);
void		black_img(t_data *img, int width, int height);
void		draw_line(t_data *img, t_fdf_point *a, t_fdf_point *b);
void		free_file_points(t_fdf_point ***file_points);
t_fdf_point	***free_failed_points(t_fdf_point ***file_points, int i);
void		get_2d_coor(t_fdf_point ***file_points);
t_fdf_point	***parsing(char *file_name);
void		pix_put(t_data *data, int x, int y, int color);
void		print_points_coordinates(t_fdf_point ***file_points);
int			print_tab(t_fdf_point ***tab);
void		put_tab(t_fdf_point ***tab, t_data *img);
int			ft_round(float n);

#endif
