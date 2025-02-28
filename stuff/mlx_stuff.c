/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:25:05 by miovu             #+#    #+#             */
/*   Updated: 2025/02/21 17:18:37 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

// create image
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	main()
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int		y;
// 	int		x;
	
// 	y = 0;
// 	x = 0;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, S_WIDTH, S_HEIGHT, "Hello world!");
// 	img.img = mlx_new_image(mlx, S_WIDTH, S_HEIGHT);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	while (y < (S_HEIGHT / 4))
// 	{
// 		x = 0;
// 		//my_mlx_pixel_put(&img, x, y, 0x00FF0000);
// 		while (x < S_WIDTH / 4)
// 		{
// 			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

/////////////////////////////////////////////////////////////////
// keys
int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("keycode: %d\n", keycode);
	if (keycode == 49)
		printf("Hello from key_hook!\n");
	else if (keycode == 65307)
		window_destroy(vars);
	return (0);
}

// int	main(void)
// {
// 	t_vars	vars;
	
// 	window_init(&vars);
// 	mlx_hook(vars.win, 17, 0, &window_destroy, &vars);
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }

//////////////////////////////////////////////////////////////////
// init_destroy
int window_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	window_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 640, 480, "Hello world!");
}