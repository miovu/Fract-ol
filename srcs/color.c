/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:21:34 by miovu             #+#    #+#             */
/*   Updated: 2025/03/20 13:03:12 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	palette_1(t_fractal *fractal)
{
	double	t;

	t = (double)fractal->i / fractal->iterations;
	fractal->color.red = (int)(9 * (1 - t) * t * t * t * 255);
	fractal->color.green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	fractal->color.blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	if (fractal->color.red > 255)
		fractal->color.red = 255;
	else if (fractal->color.green > 255)
		fractal->color.green = 255;
	else if (fractal->color.blue > 255)
		fractal->color.blue = 255;
	return (fractal->color.red << 16 | fractal->color.green << 8
		| fractal->color.blue);
}

int	palette_2(t_fractal *fractal)
{
	double	t;

	t = (double)fractal->i / fractal->iterations;
	fractal->color.red = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	fractal->color.green = (int)(8.5 * (1 - t) * (1 - t) * t * 255);
	fractal->color.blue = (int)(15 * (1 - t) * t * t * 255);
	if (fractal->color.red > 255)
		fractal->color.red = 255;
	else if (fractal->color.green > 255)
		fractal->color.green = 255;
	else if (fractal->color.blue > 255)
		fractal->color.blue = 255;
	return (fractal->color.blue << 16 | fractal->color.red << 8
		| fractal->color.green);
}

int	palette_3(t_fractal *fractal)
{
	double	t;

	t = (double)fractal->i / fractal->iterations;
	fractal->color.red = (int)(8.5 * (1 - t) * (1 - t) * t * 255);
	fractal->color.green = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	fractal->color.blue = (int)(15 * (1 - t) * t * t * 255);
	if (fractal->color.red > 255)
		fractal->color.red = 255;
	else if (fractal->color.green > 255)
		fractal->color.green = 255;
	else if (fractal->color.blue > 255)
		fractal->color.blue = 255;
	return (fractal->color.green << 16 | fractal->color.blue << 8
		| fractal->color.red);
}

int	chose_palette(t_fractal *fractal)
{
	if (fractal->palette == 1)
		return (palette_1(fractal));
	else if (fractal->palette == 2)
		return (palette_2(fractal));
	else if (fractal->palette == 3)
		return (palette_3(fractal));
	return (0);
}
