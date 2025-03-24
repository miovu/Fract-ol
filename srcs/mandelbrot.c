/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:58:14 by miovu             #+#    #+#             */
/*   Updated: 2025/03/20 12:59:44 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	calculate_mandelbrot(double real, double im, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	z.real = 0.0;
	z.im = 0.0;
	c.real = real;
	c.im = im;
	fractal->i = 0;
	while (fractal->i < fractal->iterations)
	{
		z = sum(square(z), c);
		if ((z.real * z.real + z.im * z.im) > fractal->escape)
			return (fractal->i);
		fractal->i++;
	}
	return (fractal->iterations);
}
