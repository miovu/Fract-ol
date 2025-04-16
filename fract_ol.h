/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:17:12 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/04/16 15:36:27 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

//WINDOW
# define S_HEIGHT	1000
# define S_WIDTH	1000

# define ERROR_MESSAGE "ERROR\n"

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
# define RESET		114
# define JULIA		106

//COLORS
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF

//LIBRARYS
# include "includes/libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

//COMPLEX
typedef struct s_complex
{
	double	real;
	double	im;
}				t_complex;

//COLOR
typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

//ZOOM
typedef struct s_zoom
{
	double	zoom_factor;
	double	real_range;
	double	im_range;
	double	real_step;
	double	im_step;
	double	mouse_real;
	double	mouse_im;
	double	new_real_range;
	double	im_center;
	double	new_im_min;
}				t_zoom;

//IMAGE
typedef struct s_image
{
	void	*img;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
}				t_image;

//FRACTAL
typedef struct s_fractal
{
	char		*name;
	int			type;
	void		*mlx_connection;
	void		*mlx_window;
	int			iterations;
	int			i;
	int			palette;
	double		escape;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		max;
	double		min;
	t_complex	julia;
	t_color		color;
	t_zoom		mouse;
	t_image		image;
}				t_fractal;

//MAIN
int			main(int argc, char **argv);
//PARSING
int			error_message(void);
void		key_instructions(t_fractal *fractal);
void		fractal_parsing(int argc, char **argv, t_fractal *fractal);
//MANDELBROT
int			calculate_mandelbrot(double real, double im, t_fractal *fractal);
//JULIA
int			calculate_julia(double real, double im, t_fractal *fractal);
void		julia_prespective(t_fractal *fractal);
//BURNING SHIP
int			calculate_burning_ship(double real, double im, t_fractal *fractal);
//MATH_UTILS
double		scale(double nbr, double new_min, double new_max, double old_max);
t_complex	sum(t_complex a, t_complex b);
t_complex	square(t_complex z);
//INIT
void		data_init(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
//RENDER
void		my_pixel_put(int x, int y, t_image *img, int color);
void		handle_pixel(int x, int y, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
//EVENTS
void		events_init(t_fractal *fractal);
int			close_handler(t_fractal *fractal);
void		shift(t_fractal *fractal, int key);
int			key_handler(int key, t_fractal *fractal);
//ZOOM
void		zoom(t_fractal *fractal, int key);
double		interpolate(double target, double current, double factor);
int			mouse_handler(int x, int y, int key, t_fractal *fractal);
//COLOR
int			palette_1(t_fractal *fractal);
int			palette_2(t_fractal *fractal);
int			palette_3(t_fractal *fractal);
int			chose_palette(t_fractal *fractal);

#endif