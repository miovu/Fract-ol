/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:28:15 by miovu             #+#    #+#             */
/*   Updated: 2025/03/20 12:58:19 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	calculate_burning_ship(double real, double im, t_fractal *fractal)
{
	double		temp_real;
	double		temp_im;
	t_complex	z;
	t_complex	c;

	c.real = real;
	c.im = im;
	z.real = 0.0;
	z.im = 0.0;
	fractal->i = 0;
	while (fractal->i < fractal->iterations)
	{
		temp_real = z.real * z.real - z.im * z.im + c.real;
		temp_im = 2 * fabs(z.real * z.im) + c.im;
		z.real = fabs(temp_real);
		z.im = fabs (temp_im);
		if (z.real * z.real + z.im * z.im > fractal->escape)
			break ;
		fractal->i++;
	}
	return (fractal->i);
}
