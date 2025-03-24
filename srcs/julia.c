/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:08:25 by miovu             #+#    #+#             */
/*   Updated: 2025/03/20 13:00:15 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	calculate_julia(double real, double im, t_fractal *fractal)
{
	t_complex	z;

	z.real = real;
	z.im = im;
	fractal->i = 0;
	while (fractal->i < fractal->iterations)
	{
		z = sum(square(z), fractal->julia);
		if ((z.real * z.real + z.im * z.im) > fractal->escape)
			return (fractal->i);
		fractal->i++;
	}
	return (fractal->iterations);
}
