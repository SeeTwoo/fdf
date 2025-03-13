/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:31:56 by walter            #+#    #+#             */
/*   Updated: 2025/03/13 19:47:36 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

/*the mlx is shit and my code is bad so name have to be super short to fit the
80 character limit, they will therefore be explained in comments :(
*/

typedef struct s_point	t_point;
typedef struct s_line	t_line;
typedef struct s_arg	t_arg;
typedef struct s_data	t_data;
typedef struct s_color	t_color;

/*the x, y and z are the real 3d coordinates and the 2d ones are for the
computer screen*/

struct s_point
{
	int	z;
	int	x;
	int	y;
	int	x_2d;
	int	y_2d;
	int	color;
};

struct s_line
{
	int		x_start;
	int		y_start;
	int		color_start;
	int		x_finish;
	int		y_finish;
	int		color_finish;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		length;
	int		step;
	float	t;
};

/*bpx = bits per pixels, ln_len = line length and endn = endian*/

struct s_data
{
	void	*img;
	char	*addr;
	int		bpx;
	int		ln_len;
	int		endn;
};

/*ppl = points per line, lpc = line per columns*/

struct s_arg
{
	t_point	***file_points;
	int		ppl;
	int		lpc;
	t_data	img;
	void	*mlx;
	void	*mlx_win;
};

struct s_color
{
	int	r1;
	int	g1;
	int	b1;
	int	r2;
	int	g2;
	int	b2;
};

#endif
