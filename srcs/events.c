/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:17:12 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/03/03 19:21:29 by miovu            ###   ########.fr       */
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
	/* printf("Key Pressed: %d\n", key); */
    if (key == 65307)
        close_handler(fractal);
    if (key == 65361)
        fractal->shift_x += (0.5 * fractal->zoom);
    else if (key == 65363)
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if (key == 65362)
        fractal->shift_y -= (0.5 * fractal->zoom);
    else if (key == 65364)
        fractal->shift_y += (0.5 * fractal->zoom);
    else if (key == 65451)
		fractal->iterations += 10;
    else if (key == 65453)
	{
		if (fractal->iterations > 15)
    		fractal->iterations -= 10;
	}
    fractal_render(fractal);
    return (0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    // printf("Mouse Position: x = %d, y = %d\n", x, y);
    double mouse_x, mouse_y;
	double new_zoom;
	
	new_zoom = fractal->zoom;
	mouse_x = scale(x, -2, 2, S_WIDTH);
    mouse_y = scale(y, 2, -2, S_HEIGHT);
	if (button == 4)
	{
		fractal->zoom *= 1.1;
	}
	else if (button == 5)
	{
		fractal->zoom *= 0.9;
	}

	fractal->shift_x += (mouse_x - fractal->shift_x) * (fractal->zoom / new_zoom);
    fractal->shift_y += (mouse_y - fractal->shift_y) * (fractal->zoom / new_zoom);
	fractal_render(fractal);
    return (0);
}
