/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:58:14 by miovu             #+#    #+#             */
/*   Updated: 2025/04/11 17:14:00 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	events_init(t_fractal *fractal)
{
	mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
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
		fractal->shift_x -= (0.5 * fractal->zoom / fractal->mouse.zoom_factor);
	else if (key == RIGHT || key == D)
		fractal->shift_x += (0.5 * fractal->zoom / fractal->mouse.zoom_factor);
	else if (key == UP || key == W)
		fractal->shift_y -= (0.5 * fractal->zoom / fractal->mouse.zoom_factor);
	else if (key == DOWN || key == S)
		fractal->shift_y += (0.5 * fractal->zoom / fractal->mouse.zoom_factor);
	else if (key == PLUS)
		fractal->iterations += 10;
	else if (key == MINUS && fractal->iterations > 15)
		fractal->iterations -= 10;
	else if (key == ONE)
		fractal->palette = 1;
	else if (key == TWO)
		fractal->palette = 2;
	else if (key == THREE)
		fractal->palette = 3;
	else if (key == RESET)
		data_init(fractal);
	else if (key == JULIA)
		julia_prespective(fractal);
	fractal_render(fractal);
	return (0);
}

double	interpolate(double target, double current, double factor)
{
	return (target + (current - target) * factor);
}

int	mouse_handler(int key, int x, int y, t_fractal *fractal)
{
	fractal->mouse.real_range = fractal->max - fractal->min;
	fractal->mouse.im_range = fractal->mouse.real_range; // manter aspect ratio
	fractal->mouse.real_step = fractal->mouse.real_range / (S_WIDTH - 1);
	fractal->mouse.im_step = fractal->mouse.im_range / (S_HEIGHT - 1);
	if (key == ZOOM_IN)
		fractal->mouse.zoom_factor = 1.1;
	else if (key == ZOOM_OUT)
		fractal->mouse.zoom_factor = 0.9;
	// Traduzir as coordenadas do rato para o plano complexo
	fractal->mouse.mouse_real = fractal->min + x * fractal->mouse.real_step + fractal->shift_x;
	fractal->mouse.mouse_im = fractal->min + y * fractal->mouse.im_step + fractal->shift_y;
	// zoom centrado no rato
	fractal->min = interpolate(fractal->mouse.mouse_real, fractal->min
		+ fractal->shift_x, fractal->mouse.zoom_factor);
	fractal->max = interpolate(fractal->mouse.mouse_real, fractal->max
		+ fractal->shift_x, fractal->mouse.zoom_factor);
	fractal->shift_x = 0;
	fractal->mouse.new_real_range = fractal->max - fractal->min;
	// Acrobacia para manter a posição vertical do rato no lugar certo
	fractal->mouse.im_center = fractal->mouse.mouse_im;
	fractal->mouse.new_im_min = fractal->mouse.im_center
		- ((y * (fractal->mouse.new_real_range / (S_HEIGHT - 1))));
	fractal->shift_y = fractal->mouse.new_im_min - fractal->min;
	fractal_render(fractal);
	return (0);
}
