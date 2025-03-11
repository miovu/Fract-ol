/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:58:14 by miovu             #+#    #+#             */
/*   Updated: 2025/03/11 18:06:32 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void    events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
    //printf("yes\n");
	//mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
    mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_handler, fractal);
	//printf("yes\n");
}

int close_handler(t_fractal *fractal)
{
	printf("yes\n");
    mlx_destroy_image(fractal->mlx_connection, fractal->image.img);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}

int key_handler(int key, t_fractal *fractal)
{
	// printf("Key pressed: %d\n", key);
    if (key == ESC)
        close_handler(fractal);
	else if (key == C)
	{
		// fractal->color.red   = fmod(fractal->color.red + 0.1, 1.0);
		// fractal->color.green = fmod(fractal->color.green + 0.1, 1.0);
		// fractal->color.blue  = fmod(fractal->color.blue + 0.1, 1.0);
		// fractal->color.norm = fmod(fractal->color.norm + 0.1, 1.0);
		fractal->color.norm += 0.1;
		if (fractal->color.norm >= 1.0)
			fractal->color.norm = 0.0;
		fractal_render(fractal, 0);
	}
    else if (key == LEFT || key == A)
        fractal->shift_x += (0.5 * fractal->zoom);
    else if (key == RIGHT || key == D)
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if (key == UP || key == W)
        fractal->shift_y -= (0.5 * fractal->zoom);
    else if (key == DOWN || key == S)
        fractal->shift_y += (0.5 * fractal->zoom);
    else if (key == PLUS)
		fractal->iterations += 10;
    else if (key == MINUS)
	{
		if (fractal->iterations > 15)
    		fractal->iterations -= 10;
	}
	// fractal_render(fractal, time);
    return (0);
}
