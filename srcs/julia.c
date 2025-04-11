/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:08:25 by miovu             #+#    #+#             */
/*   Updated: 2025/04/11 17:14:44 by miovu            ###   ########.fr       */
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

void	julia_prespective(t_fractal *fractal)
{
	static int	index = 0;

	if (index == 0)
	{
		fractal->julia.im = -0.2321;
		fractal->julia.real = -0.835;
	}
	else if (index == 1)
	{
		fractal->julia.im = -0.3842;
		fractal->julia.real = -0.70176;
	}
	else if (index == 2)
	{
		fractal->julia.im = 0.1428;
		fractal->julia.real = 0.45;
	}
	else if (index == 3)
	{
		fractal->julia.im = -0.1;
		fractal->julia.real = 0.37;
	}
	index = (index + 1) % 4;
}
