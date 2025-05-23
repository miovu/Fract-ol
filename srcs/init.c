/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:22:36 by miovu             #+#    #+#             */
/*   Updated: 2025/04/11 17:14:19 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	data_init(t_fractal *fractal)
{
	fractal->escape = 4;
	fractal->iterations = 50;
	fractal->i = 0;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->max = 2.0;
	fractal->min = -2.0;
	fractal->palette = 1;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		ft_printf(ERROR_MESSAGE);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			S_WIDTH, S_HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		ft_printf(ERROR_MESSAGE);
	}
	fractal->image.img = mlx_new_image(fractal->mlx_connection,
			S_WIDTH, S_HEIGHT);
	if (fractal->image.img == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		ft_printf(ERROR_MESSAGE);
	}
	fractal->image.pixels = mlx_get_data_addr(fractal->image.img,
			&fractal->image.bpp, &fractal->image.line_len,
			&fractal->image.endian);
	data_init(fractal);
	events_init(fractal);
}
