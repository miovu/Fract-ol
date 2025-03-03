/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:17:12 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/03/03 18:12:30 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define LC_HEX "0123456789abcdef"
# define UP_HEX	"0123456789ABCDEF"
# define DEC 	"0123456789"

# define S_HEIGHT	800
# define S_WIDTH	800

# define ERROR_MESSAGE "ERROR\n"

//COLORS
//Basic
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
//Others
# define MAGENTA_BURST		0xFF0000
# define LIME_SHOCK			0xCCFF00
# define NEON_ORANGE		0xFF6600
# define PSYCHEDELIC_PURPLE	0x660066
# define AQUA_DREAM			0x33CCCC
# define HOT_PINK			0xFF66B2
# define ELETRIC_BLUE		0x0066FF
# define LAVA_RED			0xFF3300


# include "includes/libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

//IMAGE
typedef struct s_image
{
	void	*img;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
}				t_image;


//FRACTAL ID
typedef struct s_fractal
{
	char	*name;
	//MLX
	void	*mlx_connection;
	void	*mlx_window;
	//IMAGE
	t_image	image;
	//HOOKS VARIABLES
	double	escape; //escape value
	int		iterations; //iterations definition
	double	shift_x;
	double	shift_y;
	double	zoom;
}				t_fractal;


//fract_ol
int			main(int argc, char **argv);

//init
void		data_init(t_fractal *fractal);
void		events_init(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);

//render
void		my_pixel_put(int x, int y, t_image *img, int color);
void		handel_pixel(int x, int y, t_fractal *fractal);
void 		fractal_render(t_fractal *fractal);

//math_utils
double 		scale(double unscaled_num, double new_min, double new_max, double old_max);
t_complex   sum(t_complex a, t_complex b);
t_complex   square(t_complex z);

//events
int    		close_handler(t_fractal *fractal);
int 		key_handler(int key, t_fractal *fractal);
int 		mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif