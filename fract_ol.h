/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:22:45 by miovu             #+#    #+#             */
/*   Updated: 2025/02/21 18:06:32 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define LC_HEX "0123456789abcdef"
# define UP_HEX	"0123456789ABCDEF"
# define DEC "0123456789"

# define S_HEIGHT 2160
# define S_WIDTH 3840

# define ERROR_MESSAGE "Please enter \n\t""

# include "includes/libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <ctype.h>
# include <stdbool.h>
# include <math.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_complex
{
	// x
	double	real;
	// y
	double	i;
}				t_complex;

// mlx stuff
int		key_hook(int keycode, t_vars *vars);
int		main(void);
int		window_destroy(t_vars *vars);
void	window_init(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif