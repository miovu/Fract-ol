/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:17:12 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/03/15 17:07:41 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define S_HEIGHT	800
# define S_WIDTH	800

# define ERROR_MESSAGE "ERROR\n"

# define PI 3.14159265358979323846

//KEYS
# define UP			65362
# define W			119
# define DOWN		65364
# define S			115
# define RIGHT		65363
# define D			100
# define LEFT		65361
# define A			97
# define MINUS		65453
# define PLUS		65451
# define ESC		65307
# define ZOOM_IN	5
# define ZOOM_OUT	4
# define ONE		49
# define TWO		50
# define THREE		51

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
# define DEEP_PURPLE 0x5D1F6E   // Deep Purple
# define DARK_GREEN  0x0A4F2D   // Dark Green
# define ELECTRIC_BLUE 0x0066FF // Electric Blue
# define NEON_PINK   0xFF0099   // Neon Pink
# define VIVID_TURQUOISE 0x00B3B3 // Vivid Turquoise
# define DARK_RED    0x9E0E0E   // Dark Red

# include "includes/libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_complex
{
	double	real;
	double	im;
}				t_complex;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef	struct s_palette
{
	int		palette_1;
	int		palette_2;
	int		palette_3;
}				t_palette;

typedef struct s_image
{
	void	*img;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
}				t_image;

typedef	struct s_fractal
{
	char	*name;
	int		type;
	int		typel;
	void	*mlx_connection;
	void	*mlx_window;
	t_image	image;
	double	escape; //escape value
	int		iterations; //iterations definition
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	max;
	double	min;
	double	inp1;//real part
	double	inp2;//im part
	double	inp3;//multiplied 
	t_complex	J;
	t_color		color;
	t_palette	palette;
	//double	mouse_x;
	//double	mouse_y;
}				t_fractal;

//Main
int			main(int argc, char **argv);
//Parsing
int			error_message(void);
void		fractal_parsing(int argc, char **argv, t_fractal *fractal);
//Mandelbrot
int			calculate_mandelbrot(double real, double im, t_fractal *fractal);
//Julia
double		ft_atof(const char *str, double result, double sign, double decimal);
int			calculate_julia(double real, double im, t_fractal *fractal);
//Phoenix
int			calculate_phoenix(double real, double im, t_fractal *fractal);
//Math_utils
double  	scale(double unscaled_num, double new_min, double new_max, double old_max);
t_complex   sum(t_complex a, t_complex b);
t_complex   square(t_complex z);
//Init
void    	data_init(t_fractal *fractal);
void    	fractal_init(t_fractal *fractal);
//Render
void 		my_pixel_put(int x, int y, t_image *img, int color);
void 		handle_pixel(int x, int y, t_fractal *fractal);
void    	fractal_render(t_fractal *fractal);
//Events
void    	events_init(t_fractal *fractal);
int 		close_handler(t_fractal *fractal);
int 		key_handler(int key, t_fractal *fractal);
//Color
int			palette_1(int i, t_fractal *fractal);
// int			palette_2(int i, t_fractal *fractal);
// int			palette_3(int i, t_fractal *fractal);

#endif