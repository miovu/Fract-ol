/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:19:03 by miovu             #+#    #+#             */
/*   Updated: 2025/03/15 17:34:36 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	error_message(void)
{
	write(1, "\033[1;31mError!\n[0m", 14);
	write(1, "\033[1;34mUsage:\n", 15);
	write(1, "\033[0m\t./fract_ol <Chosen Fractal>\n", 33);
	write(1, "\033[1;34mAvaliable Fractals:\n[0m", 27);
	write(1, "\033[0m\t-Mandelbrot\n", 17);
	write(1, "\033[0m\t-Phoenix\n", 14);
	write(1, "\033[0m\t-Julia\n", 12);
	exit(EXIT_FAILURE);
	return (0);
}

void	fractal_parsing(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && (!ft_strncmp(argv[1], "Mandelbrot", 10)))
		fractal->type = 0;
	else if (argc == 4 && (!ft_strncmp(argv[1], "Julia", 5)))
		{
			fractal->type = 1;
			fractal->J.real = ft_atof(argv[2], 0.0, 1.0, 1.0);
			fractal->J.im = ft_atof(argv[3], 0.0, 1.0, 1.0);
		}
	else if (argc == 5 && (!ft_strncmp(argv[1], "Phoenix", 8)))
		{
			fractal->type = 2;
			fractal->inp1 = ft_atof(argv[2], 0.0, 1.0, 1.0);
			fractal->inp2 = ft_atof(argv[3], 0.0, 1.0, 1.0);
			fractal->inp3 = ft_atof(argv[4], 0.0, 1.0, 1.0);
		}
	else
	{
		error_message();
		exit(EXIT_FAILURE);
	}
}
