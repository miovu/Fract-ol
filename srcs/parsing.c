/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:19:03 by miovu             #+#    #+#             */
/*   Updated: 2025/04/11 17:15:49 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	error_message(void)
{
	ft_printf("\033[1;31mError!\n[0m");
	ft_printf("\033[1;34mUsage:\n");
	ft_printf("\033[0m\t./fract_ol <Chosen Fractal>\n");
	ft_printf("\033[1;34mAvailable Fractals:\n[0m");
	ft_printf("\033[0m\t-Mandelbrot\n");
	ft_printf("\033[0m\t-Burning Ship\n");
	ft_printf("\033[0m\t-Julia\n");
	exit(EXIT_FAILURE);
	return (0);
}

void	key_instructions(t_fractal *fractal)
{
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 18, 40, WHITE,
		"Arrow keys or WASD to move around");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 18, 60, WHITE,
		"'1' '2' '3' to change the color palette");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 18, 80, WHITE,
		"Mouse wheel to zoom in and out");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 18, 100, WHITE,
		"'R' to reset the view");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 18, 120, WHITE,
		"'+' to increase iterations");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 18, 140, WHITE,
		"'-' to decrease iterations");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 18, 160, WHITE,
		"'J' to change Julia's view");
}

void	fractal_parsing(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && (!ft_strncmp(argv[1], "Mandelbrot", 10)))
	{
		fractal->name = "Mandelbrot";
		fractal->type = 0;
	}
	else if (argc == 4 && (!ft_strncmp(argv[1], "Julia", 5)))
	{
		fractal->name = "Julia";
		fractal->type = 1;
		fractal->julia.real = ft_atof(argv[2], 0.0, 1.0, 1.0);
		fractal->julia.im = ft_atof(argv[3], 0.0, 1.0, 1.0);
	}
	else if (argc == 3 && (!ft_strncmp(argv[1], "Burning", 7))
		&& (!ft_strncmp(argv[2], "Ship", 4)))
	{
		fractal->name = "Burning Ship";
		fractal->type = 2;
	}
	else
	{
		error_message();
		exit(EXIT_FAILURE);
	}
}
