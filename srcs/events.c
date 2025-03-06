/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:17:12 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/03/05 19:37:29 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->image.img);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}

int key_handler(int key, t_fractal *fractal)
{
    if (key == ESC)
        close_handler(fractal);
    if (key == LEFT)
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if (key == RIGHT)
        fractal->shift_x += (0.5 * fractal->zoom);
    else if (key == UP)
        fractal->shift_y += (0.5 * fractal->zoom);
    else if (key == DOWN)
        fractal->shift_y -= (0.5 * fractal->zoom);
    else if (key == PLUS)
		fractal->iterations += 10;
    else if (key == MINUS)
	{
		if (fractal->iterations > 15)
    		fractal->iterations -= 10;
	}
    fractal_render(fractal);
    return (0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    //printf("Mouse Position: x = %d, y = %d\n", x, y);
    // double mouse_x;
	// double mouse_y;
	// double new_zoom;
	// new_zoom = fractal->zoom;
	// mouse_x = scale(x, -2, 2, S_WIDTH);
    // mouse_y = scale(y, 2, -2, S_HEIGHT);
	if (button == 5)
	{
		fractal->zoom *= 1.05;
		if (scale(x, fractal->min, fractal->max, S_WIDTH) > 0)
			fractal->mouse_x += scale(x, fractal->min, fractal->max, S_WIDTH) * fractal->zoom * 0.25;
		else
			fractal->mouse_x -= scale(x, fractal->min, fractal->max, S_WIDTH) * fractal->zoom * 0.25;
		if (scale(y, fractal->min, fractal->max, S_WIDTH) < 0)
			fractal->mouse_y += scale(y, fractal->min, fractal->max, S_WIDTH) * fractal->zoom * 0.25;
		else
			fractal->mouse_y -= scale(y, fractal->min, fractal->max, S_WIDTH) * fractal->zoom * 0.25;
		printf("fractal->mouse_x: %f\n", fractal->mouse_x);
		printf("fractal->mouse_y: %f\n", fractal->mouse_y);
		// fractal->min *= fractal->zoom;
		// fractal->max *= fractal->zoom;
		// x = scale(x, fractal->min, fractal->max, S_WIDTH);
    	// y = scale(y, fractal->max, fractal->min, S_HEIGHT);
	}
	else if (button == 4)
	{
		fractal->zoom *= 0.95;
		if (scale(x, fractal->min, fractal->max, S_WIDTH) > 0)
			fractal->mouse_x -= scale(x, fractal->min, fractal->max, S_WIDTH) * fractal->zoom * 0.25;
		else
			fractal->mouse_x += scale(x, fractal->min, fractal->max, S_WIDTH) * fractal->zoom * 0.25;
		if (scale(y, fractal->min, fractal->max, S_WIDTH) < 0)
			fractal->mouse_y -= scale(y, fractal->min, fractal->max, S_WIDTH) * fractal->zoom * 0.25;
		else
			fractal->mouse_y += scale(y, fractal->min, fractal->max, S_WIDTH) * fractal->zoom * 0.25;
		printf("fractal->mouse_x: %f\n", fractal->mouse_x);
		printf("fractal->mouse_y: %f\n", fractal->mouse_y);
		// fractal->min *= fractal->zoom;
		// fractal->max *= fractal->zoom;
		// x = scale(x, fractal->min, fractal->max, S_WIDTH);
    	// y = scale(y, fractal->max, fractal->min, S_HEIGHT);
	}
	// fractal->shift_x += (x - fractal->shift_x) * (fractal->zoom / new_zoom);
    // fractal->shift_y += (y - fractal->shift_y) * (fractal->zoom / new_zoom);
	fractal_render(fractal);
	//printf("Mouse Position: x = %d, y = %d\n", x, y);
    return (0);
}
