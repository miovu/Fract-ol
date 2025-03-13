/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:02:37 by miovu             #+#    #+#             */
/*   Updated: 2025/03/13 17:03:47 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	calculate_phoenix(double real, double im, t_fractal *fractal)
{
	t_complex	z;
	double		temp;
	int			i;

	z.real = real;
	z.im = im;
	i = 0;
	while (i < fractal->iterations)
	{
		temp = z.real;
		z.real = (z.real * z.real * z.real) - (3 * z.real * z.im * z.im) + real;
		z.im = (3 * temp * temp * z.im) - (z.im * z.im * z.im) + z.im;
		if ((z.real * z.real + z.im * z.im) > fractal->escape)
			return (i);
		i++;
	}
	return (fractal->iterations);
}
