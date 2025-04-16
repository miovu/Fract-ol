/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:58:14 by miovu             #+#    #+#             */
/*   Updated: 2025/04/16 15:11:19 by miovu            ###   ########.fr       */
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

void	shift(t_fractal *fractal, int key)
{
	double	range;
	double	step;

	range = fractal->max - fractal->min;
	step = range * 0.05;
	if (key == LEFT || key == A)
		fractal->shift_x -= step;
	else if (key == RIGHT || key == D)
		fractal->shift_x += step;
	else if (key == UP || key == W)
		fractal->shift_y -= step;
	else if (key == DOWN || key == S)
		fractal->shift_y += step;
}

int	key_handler(int key, t_fractal *fractal)
{
	if (key == ESC)
		close_handler(fractal);
	else if (key == LEFT || key == A || key == RIGHT || key == D
		|| key == UP || key == W || key == DOWN || key == S)
		shift(fractal, key);
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
