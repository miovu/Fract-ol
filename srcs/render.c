/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:37:37 by miovu             #+#    #+#             */
/*   Updated: 2025/03/19 17:30:29 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void my_pixel_put(int x, int y, t_image *img, int color)
{
    int result;
    
    result = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels + result) = color;
}

void handle_pixel(int x, int y, t_fractal *fractal)
{
    double	real;
	double	im;
	int		color;

	real = scale(x, fractal->min, fractal->max, S_WIDTH) * fractal->zoom + fractal->shift_x;
	im = scale(y, fractal->min, fractal->max, S_HEIGHT) * fractal->zoom + fractal->shift_y;
	color = 0;
	fractal->i = 0;
	if (fractal->type == 0)
		fractal->i = calculate_mandelbrot(real, im, fractal);
    else if (fractal->type == 1)
        fractal->i = calculate_julia(real, im, fractal);
	else if (fractal->type == 2)
		fractal->i = calculate_burning_ship(real, im, fractal);
	if (fractal->i == fractal->iterations)
		color = BLACK;
	else
        color = chose_palette(fractal->palette, fractal);
	my_pixel_put(x, y, &fractal->image, color);
}

void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while (y < S_HEIGHT)
    {
        x = 0;
        while (x < S_WIDTH)
        {
            handle_pixel(x, y, fractal);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.img, 0, 0);
}
