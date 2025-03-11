/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:37:37 by miovu             #+#    #+#             */
/*   Updated: 2025/03/11 18:08:47 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void my_pixel_put(int x, int y, t_image *img, int color)
{
    int result;
    
    result = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels + result) = color;
}

void handle_pixel(int x, int y, t_fractal *fractal, double time)
{
	t_color	c;
    double	real;
	double	im;
	int		i;
	int		color;

	real = scale(x, fractal->min, fractal->max, S_WIDTH) * fractal->zoom + fractal->shift_x;
	im = scale(y, fractal->max, fractal->min, S_HEIGHT) * fractal->zoom + fractal->shift_y;
	color = 0;
	i = 0;
	if (fractal->type == 0)
		i = calculate_mandelbrot(real, im, fractal);
	else if (fractal->type == 1)
		i = calculate_julia(real, im, fractal);
	if (i == fractal->iterations)
		color = BLACK;
	else
		color = calculate_color(i, time, fractal, &c);
	my_pixel_put(x, y, &fractal->image, color);
}

void    fractal_render(t_fractal *fractal, double time)
{
    int x;
    int y;

    y = 0;
    while (y < S_HEIGHT)
    {
        x = 0;
        while (x < S_WIDTH)
        {
            handle_pixel(x, y, fractal, time);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.img, 0, 0);
}
