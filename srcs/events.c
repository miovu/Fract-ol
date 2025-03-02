/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:17:12 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/03/02 22:04:03 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//HEADER

#include "../fract_ol.h"

int close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->image.img);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_connection);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}

int key_handler(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
        close_handler(fractal);
    if (keysym == XK_Left)
        fractal->shift_x += (0.5 * fractal->zoom);
    else if (keysym == XK_Right)
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if (keysym == XK_Up)
        fractal->shift_y -= (0.5 * fractal->zoom);
    else if (keysym == XK_Down)
        fractal->shift_y += (0.5 * fractal->zoom);
    else if (keysym == XK_plus)
        fractal->iterations += 10;
    else if (keysym == XK_minus)
        fractal->iterations -= 10;

    fractal_render(fractal);
    return (0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    double  m_real;
    double  m_imaginary;
    double  zoom;
    
    m_real = (scale(x, -2, 2, S_WIDTH) * fractal->zoom) * fractal->shift_x;
    m_imaginary = (scale(y, 2, -2, S_HEIGHT) * fractal->zoom) * fractal->shift_y;
    if (button == Button5)
        zoom = 0.95;
    else if (button == Button4)
        zoom = 0.05;
    fractal->shift_x = m_real - (scale(x, -2, +2, S_WIDTH) * fractal->zoom * zoom);
    fractal->shift_y = m_imaginary - (scale(y, +2, -2, S_HEIGHT) * fractal->zoom * zoom);
    fractal->zoom *= zoom;
    fractal_render(fractal);
    return (0);
}