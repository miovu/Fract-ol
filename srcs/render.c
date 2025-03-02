/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:01:32 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/03/02 19:25:58 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//header

#include "../fract_ol.h"

void my_pixel_put(int x, int y, t_image *img, int color)
{
    int offset;
    
    offset = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels + offset) = color;
}

void handel_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    i = 0;
    z.x = 0.0;
    z.y = 0.0;
    c.x = (scale(x, -2, +2, S_WIDTH) * fractal->zoom) + fractal->shift_x;
    c.y = (scale(y, +2, -2, S_HEIGHT) * fractal->zoom) + fractal->shift_y;
    while (i < fractal->iterations)
    {
        z = sum(square(z), c);
        if (((z.x * z.x) + (z.y * z.y)) > fractal->escape)
        {
            color = scale(i, BLACK, WHITE, fractal->iterations);
            my_pixel_put(x, y, &fractal->image, color);
            return ;
        }
        ++i;
    }
    my_pixel_put(x, y, &fractal->image, PSYCHEDELIC_PURPLE);
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
            handel_pixel(x, y, fractal);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.img, 0, 0);
}
