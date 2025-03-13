/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:21:34 by miovu             #+#    #+#             */
/*   Updated: 2025/03/13 14:59:09 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	palette_1(int i, t_fractal *fractal)
{
	double	t;
	
	t = (double)i / fractal->iterations;
	fractal->color.red = (int)(9 * (1 - t) * t * t * t * 255);
	fractal->color.green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	fractal->color.blue = (int)(8.5 * (1 - t) * ( 1 - t) * (1 - t) * t * 255);
	return (fractal->color.red << 16 | fractal->color.green << 8 | fractal->color.blue);
}

// int	palette_2(int i, t_fractal *fractal)
// {
// 	double	t;

// 	t = (double)i / fractal->iterations;
// 	fractal->color.red = (int)(255 * t);
// 	fractal->color.green = 0;
// 	fractal->color.blue = (int)(255 * (1 - t));
// 	return (fractal->color.red << 16 | fractal->color.green << 8 | fractal->color.blue);
// }

// int	palette_3(int i, t_fractal *fractal)
// {
// 	double	t;

// 	t = (double)i / fractal->iterations;
// 	fractal->color.red = (int)(128 * (sin(t * 6.0) + 1));
// 	fractal->color.green = (int)(128 * (cos(t * 4.0) + 1));
// 	fractal->color.blue = (int)(128 * (sin(t * 2.0) + 1));
// 	return (fractal->color.red << 16 | fractal->color.green << 8 | fractal->color.blue);
// }
