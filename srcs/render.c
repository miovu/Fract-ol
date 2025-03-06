/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:17:12 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/03/05 19:31:17 by miovu            ###   ########.fr       */
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
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    i = 0;
    z.real = 0.0;
    z.im = 0.0;
	
    c.real = (scale(x, fractal->min, fractal->max, S_WIDTH) * fractal->zoom) + fractal->shift_x + fractal->mouse_x;
    c.im = (scale(y, fractal->max, fractal->min, S_HEIGHT) * fractal->zoom) + fractal->shift_y + fractal->mouse_y;
    while (i < fractal->iterations)
    {
        z = sum(square(z), c);
        if (((z.real * z.real) + (z.im * z.im)) > fractal->escape)
        {
            color = scale(i, PSYCHEDELIC_PURPLE, WHITE, fractal->iterations);
            my_pixel_put(x, y, &fractal->image, color);
            return ;
        }
        ++i;
    }
    my_pixel_put(x, y, &fractal->image, HOT_PINK);
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
