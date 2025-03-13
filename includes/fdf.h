/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:35:52 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/13 16:04:43 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "fdf_structs.h"
# include "fdf_func.h"
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# ifndef VALID_CHARS
#  define VALID_CHARS "-0123456789"
# endif

# ifndef ESC_CODE 
#  define ESC_CODE 65307
# endif

# ifndef WIN_W
#  define WIN_W 1024
# endif

# ifndef WIN_H
#  define WIN_H 780
# endif

#endif
