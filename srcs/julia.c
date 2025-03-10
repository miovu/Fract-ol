/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:08:25 by miovu             #+#    #+#             */
/*   Updated: 2025/03/10 17:29:00 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

double	ft_atof(const char *str, double result, double sign, double	decimal)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1.0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			result = result + (*str - '0') / (decimal *= 10);
			str++;
		}
	}
	return (result * sign);
}

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
