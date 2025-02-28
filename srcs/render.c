/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:01:32 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/02/28 00:37:43 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//header

#include "../fract_ol.h"

// z = z^2 + c
// z inicialmente é (0, 0)
// c é o ponto

//por um pixel no meu image buffer
void my_pixel_put(int x, int y, t_image *img, int color)
{
    int offset;
    
    offset = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}

void handel_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    //int         color;

    i = 0;
    //1ª iteração
    z.x = 0.0;
    z.y = 0.0;
    //as coordenadas x e y escladas pela função map para caber dentro do mandelbrot
    c.x = map(x, -2, +2, 0, S_WIDTH);
    c.y = map(y, +2, -2, 0, S_HEIGHT);
    printf("Pixel (%d, %d) mapped to Complex (%f, %f)\n", x, y, c.x, c.y);
    //quantas vezes queremos iterar para ver se o ponto escapou do mandelbrot
    while (i < fractal->iterations_definition)
    {
        printf("Iter %d: z = (%f, %f)\n", i, z.x, z.y);
        z = sum_complex(square_complex(z), c);
        //se o valor escapou
        //se a hipotenusa(escape value) for maior que 2, o ponto escapou
        if (((z.x * z.x) + (z.y * z.y)) > fractal->escape_value)
        {
            // color = map(i, BLACK, WHITE, 0, fractal->iterations_definition);
            // my_pixel_put(x, y, &fractal->image, color);
            // printf("Escaped at iteration %d for pixel (%d, %d)\n", i, x, y);
            // return ;
            break ;
        }
        ++i;
    }
    // estamos no Mandelbrot set devido às iterações feitas
    my_pixel_put(x, y, &fractal->image, PSYCHEDELIC_PURPLE);
}

void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < S_HEIGHT)
    {
        x = -1;
        while (++x < S_WIDTH)
            handel_pixel(x, y, fractal);
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.img_ptr, 0, 0);
}
