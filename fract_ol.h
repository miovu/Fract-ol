/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:22:45 by miovu             #+#    #+#             */
/*   Updated: 2025/02/28 00:11:11 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define LC_HEX "0123456789abcdef"
# define UP_HEX	"0123456789ABCDEF"
# define DEC "0123456789"

# define S_HEIGHT	800
# define S_WIDTH	800

//use a square to keep rendering math simple
# define ERROR_MESSAGE "ERROR\n"

//colors
//Basic
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED		0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
//Others
# define MAGENTA_BURST		0xFF0000
# define LIME_SHOCK			0xCCFF00
# define NEON_ORANGE			0xFF6600
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
# include <stdarg.h>
# include <ctype.h>
# include <stdbool.h>
# include <math.h>

//VALUES
typedef struct	s_complex
{
	// real
	double	x;
	// imaginary
	double	y;
}				t_complex;

//IMAGE (estes valores estão na função mlx_get_data_addr())
typedef struct s_image
{
	//values from mlx
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels - 1 byte
	int		bpp;
	int		endian;
	int		line_len;
}				t_image;


//FRACTAL ID
typedef struct s_fractal
{
	char	*name;
	//MLX
	void	*mlx_connection; //mlx_init()
	void	*mlx_window; //mlx_window()
	//IMAGE
	t_image	image;
	//HOOKS VARIABLES
	double	escape_value; //hipotnusa
	int		iterations_definition; //value tight with the image quality and rendering speed
}				t_fractal;

//main
int			main(int argc, char **argv);
//fract_ol
//init
void		data_init(t_fractal *fractal);
void		malloc_error();
void		fractal_init(t_fractal *fractal);
//render
void		my_pixel_put(int x, int y, t_image *img, int color);
void		handel_pixel(int x, int y, t_fractal *fractal);
void 		fractal_render(t_fractal *fractal);
//math_utils
double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);

#endif