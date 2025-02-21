/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:07:59 by miovu             #+#    #+#             */
/*   Updated: 2025/02/21 18:04:09 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	main(int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
		|| argc == 3 && !ft_strncmp(argv[1], "julia", 5))
	{
		
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}