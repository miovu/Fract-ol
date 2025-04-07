/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:58:14 by miovu             #+#    #+#             */
/*   Updated: 2025/04/07 16:11:11 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
}

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int key, t_fractal *fractal)
{
	if (key == ESC)
		close_handler(fractal);
	else if (key == LEFT || key == A)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (key == RIGHT || key == D)
		fractal->shift_x += (0.5 * fractal->zoom);
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
	else if (key == ONE)
		fractal->palette = 1;
	else if (key == TWO)
		fractal->palette = 2;
	else if (key == THREE)
		fractal->palette = 3;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int key, int x, int y, t_fractal *fractal)
{
	double	zoom_factor;
	double	mouse_real;
	double	mouse_im;
	
	zoom_factor = 0.0;
	mouse_real = (double)x / (S_WIDTH / (fractal->max - fractal->min)) + fractal->min + fractal->shift_x;
	mouse_im = (double)y / (S_HEIGHT / (fractal->max - fractal->min)) + fractal->min + fractal->shift_y;
	if (key == ZOOM_OUT)
		zoom_factor = 0.9;
	else if (key == ZOOM_IN)
		zoom_factor = 1.1;
	fractal->min = mouse_real - (mouse_real - fractal->min) * zoom_factor;
	fractal->max = mouse_real + (fractal->max - mouse_real) * zoom_factor;
	fractal_render(fractal);
	return (0);
}
