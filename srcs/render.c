/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:17:12 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/03/03 17:12:13 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void my_pixel_put(int x, int y, t_image *img, int color)
{
    int result;
    
    result = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels + result) = color;
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
            handel_pixel(x, y, fractal);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.img, 0, 0);
}
