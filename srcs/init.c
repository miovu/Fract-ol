/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:40:04 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/02/28 01:59:25 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// header

/* INIT 
MLX
LISTENING EVENTS
HOOKS DATA */

#include "../fract_ol.h"

void    data_init(t_fractal *fractal)
{
    fractal->escape_value = 4;  //2^2 hypotnusa
    fractal->iterations_definition = 42;
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
    // zoom factor
    fractal->zoom = 1.0;
}

//POR NO HEADER
void    events_init(t_fractal *fractal)
{
    //ver mais sobre esta função ---------
    mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
    mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler, fractal);
    mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_handler, fractal);
}

void    malloc_error()
{
    ft_printf("Problems with malloc");
    exit(EXIT_FAILURE);
}

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL)
        malloc_error();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, S_WIDTH, S_HEIGHT, fractal->name);
    if (fractal->mlx_window == NULL)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->image.img_ptr = mlx_new_image(fractal->mlx_connection, S_WIDTH, S_HEIGHT);
    if (fractal->image.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->image.pixels_ptr = mlx_get_data_addr(fractal->image.img_ptr, &fractal->image.bpp, &fractal->image.line_len, &fractal->image.endian);
    data_init(fractal);
}
