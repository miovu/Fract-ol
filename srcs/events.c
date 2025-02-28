/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:17:12 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/02/28 02:08:06 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//HEADER

#include "../fract_ol.h"

//for ESC or X in the window
int    close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->image.img_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_connection);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}


//prototipo: int    (*f)(int keycode, void *param)
//ver o que é keysym
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
        fractal->iterations_definition += 10;
    else if (keysym == XK_minus)
        fractal->iterations_definition -= 10;

    fractal_render(fractal);
    return (0);
}

//prototipo: int (*f)(int button, int x, int y, void *param)
int mouse_handler(int button, t_fractal *fractal)
{
    if (button == Button5)
    {
        fractal->zoom *= 0.95;
    }
    else if (button == Button4)
    {
        fractal->zoom *= 0.05;
    }
    fractal_render(fractal);
    return (0);
}