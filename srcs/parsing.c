/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:19:03 by miovu             #+#    #+#             */
/*   Updated: 2025/03/13 17:05:29 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	error_message(void)
{
	write(1, "\033[1;31mError!\n[0m", 14);
	write(1, "\033[1;34mUsage:\n", 16);
	write(1, "\033[0m\t./fract_ol <Chosen Fractal>\n", 33);
	write(1, "\033[1;34mAvaliable Fractals:\n[0m", 27);
	write(1, "\033[0m\t-Mandelbrot\n", 17);
	write(1, "\033[0m\t-Phoenix\n", 12);
	write(1, "\033[0m\t-Julia\n", 12);
	exit(EXIT_FAILURE);
	return (0);
}

void	fractal_parsing(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && (!ft_strncmp(argv[1], "Mandelbrot", 10)))
		fractal->type = 0;
	else if (argc == 2 && (!ft_strncmp(argv[1], "Phoenix", 8)))
		fractal->type = 1;
	else if (argc == 4 && (!ft_strncmp(argv[1], "Julia", 5)))
	{
		fractal->type = 2;
		fractal->J.real = ft_atof(argv[2], 0.0, 1.0, 1.0);
		fractal->J.im = ft_atof(argv[3], 0.0, 1.0, 1.0);
	}
	else
	{
		error_message();
		exit(EXIT_FAILURE);
	}
}
