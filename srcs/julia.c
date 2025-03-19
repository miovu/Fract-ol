/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:08:25 by miovu             #+#    #+#             */
/*   Updated: 2025/03/19 17:37:09 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	calculate_julia(double real, double im, t_fractal *fractal)
{
	t_complex	z;
	int			i;

	z.real = real;
	z.im = im;
	
	i = 0;
	while (i < fractal->iterations)
	{
		z = sum(square(z), fractal->J);
		if ((z.real * z.real + z.im * z.im) > fractal->escape)
			return (i);
		i++;
	}
	return (fractal->iterations);
}
