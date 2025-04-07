/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:58:14 by miovu             #+#    #+#             */
/*   Updated: 2025/04/07 17:31:49 by miovu            ###   ########.fr       */
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

double	interpolate(double target, double current, double factor)
{
	return (1 - factor) * target + factor * current;
}

int	mouse_handler(int key, int x, int y, t_fractal *fractal)
{
	double	zoom_factor;
	double	mouse_real;
	double	mouse_im;
	t_complex	mouse;
	double	real_range = fractal->max - fractal->min;
	double	real_step = real_range / (S_WIDTH - 1);
	double	im_step = real_range / (S_HEIGHT - 1);
	
	mouse_real = fractal->min + x * real_step + fractal->shift_x;
	mouse_im = fractal->min + y * im_step + fractal->shift_y;
	if (key == ZOOM_OUT)
		zoom_factor = 1.1;
	else if (key == ZOOM_IN)
		zoom_factor = 0.9;
	else 
		return (0);
	double	new_real_range = real_range / zoom_factor;
	fractal->min = mouse.real - (mouse.real - (fractal->min + fractal->shift_x)) * (1.0 / zoom_factor);
	fractal->max = fractal->min + new_real_range;
	fractal->shift_x = 0;
	double	new_im_center = mouse.im;
	fractal->shift_y + new_im_center - (fractal->min + fractal->max) / 2;
	fractal_render(fractal);
	return (0);
}
