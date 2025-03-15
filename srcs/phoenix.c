/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:02:37 by miovu             #+#    #+#             */
/*   Updated: 2025/03/15 17:31:29 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	calculate_phoenix(double real, double im, t_fractal *fractal)
{
	t_complex	z;
	t_complex	z_temp;
	t_complex	z_prev;
	//double		temp;
	int			i;

	z.real = real;
	z.im = im;
	z_prev.real = 0.0;
	z_prev.im = 0.0;
	i = 0;
	while (i < fractal->iterations)
	{
		z_temp = z;
		z.real = (z.real * z.real) - (z.im * z.im) + fractal->inp1 + (fractal->inp3 * z_prev.real);
		z.im = (2 * z.real * z.im) + (-1 * fractal->inp2) + (fractal->inp3 * z_prev.im);
		z_prev = z_temp;
		if ((z.real * z.real + z.im * z.im) > fractal->escape)
			break;
		i++;
	}
	return (i);
}
