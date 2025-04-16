/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:10:47 by miovu             #+#    #+#             */
/*   Updated: 2025/04/16 15:34:53 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

double	interpolate(double target, double current, double factor)
{
	return (target + (current - target) * factor);
}

void	zoom(t_fractal *fractal, int key)
{
	if (key == ZOOM_IN)
		fractal->mouse.zoom_factor = 1.1;
	else if (key == ZOOM_OUT)
		fractal->mouse.zoom_factor = 0.9;
	else
		return ;
}

int	mouse_handler(int key, int x, int y, t_fractal *fractal)
{
	zoom(fractal, key);
	fractal->mouse.real_range = fractal->max - fractal->min;
	fractal->mouse.im_range = fractal->mouse.real_range;
	fractal->mouse.real_step = fractal->mouse.real_range / (S_WIDTH - 1);
	fractal->mouse.im_step = fractal->mouse.im_range / (S_HEIGHT - 1);
	fractal->mouse.mouse_real = fractal->min + x * fractal->mouse.real_step
		+ fractal->shift_x;
	fractal->mouse.mouse_im = fractal->min + y * fractal->mouse.im_step
		+ fractal->shift_y;
	fractal->min = interpolate(fractal->mouse.mouse_real, fractal->min
			+ fractal->shift_x, fractal->mouse.zoom_factor);
	fractal->max = interpolate(fractal->mouse.mouse_real, fractal->max
			+ fractal->shift_x, fractal->mouse.zoom_factor);
	fractal->shift_x = 0;
	fractal->mouse.new_real_range = fractal->max - fractal->min;
	fractal->mouse.im_center = fractal->mouse.mouse_im;
	fractal->mouse.new_im_min = fractal->mouse.im_center
		- ((y * (fractal->mouse.new_real_range / (S_HEIGHT - 1))));
	fractal->shift_y = fractal->mouse.new_im_min - fractal->min;
	fractal_render(fractal);
	return (0);
}
