/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:06:21 by miovu             #+#    #+#             */
/*   Updated: 2025/03/11 18:01:02 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	calculate_color(int i, double time, t_fractal *fractal, t_color *c)
{
	int	color;
	double	mu;
	float color_shift;
	
	if (i == fractal->iterations)
		return (BLACK);
	color_shift = sin(time + fractal->color.norm);
	mu = (double)i - log(log2(fabs(i + 1 - log2(log2(abs(i + 1))))));
	c->norm = mu / (float)fractal->iterations;
	c->norm = pow(c->norm, 0.5);
	
	c->red = fractal->color.red + 0.5 * cos(6.0 * PI * (c->norm + color_shift) + time);
	c->green = fractal->color.green + 0.5 * cos(6.0 * PI * (c->norm + 0.33 + color_shift) + time);
	c->blue = fractal->color.blue + 0.5 * cos(6.0 * PI * (c->norm + 0.66 + color_shift) + time);

	c->red = fmin(fmax(c->red, 0.0), 1.0);
    c->green = fmin(fmax(c->green, 0.0), 1.0);
    c->blue = fmin(fmax(c->blue, 0.0), 1.0);

	color = ((int)(c->red * 255) << 16) | ((int)(c->green * 255) << 8)
			| ((int)(c->blue * 255));
	return (color);
}
