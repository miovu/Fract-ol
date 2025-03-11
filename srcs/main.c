/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:13:32 by miovu             #+#    #+#             */
/*   Updated: 2025/03/11 18:06:10 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	render_loop(t_fractal *fractal);

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	fractal_parsing(argc, argv, &fractal);
	fractal_init(&fractal);
	mlx_loop_hook(fractal.mlx_connection, render_loop, &fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}

int	render_loop(t_fractal *fractal)
{
	static double	time;

	time = 0.0;
	fractal_render(fractal, time);
	time += 0.05;
	return (0);
}