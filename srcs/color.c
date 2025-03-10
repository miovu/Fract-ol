/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:06:21 by miovu             #+#    #+#             */
/*   Updated: 2025/03/10 18:11:28 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	color(int color_code, int *pixel)
{
	 if (color_code == 1)
        *pixel = 0xFF0000;  // Red
    else if (color_code == 2)
        *pixel = 0x00FF00;  // Green
    else if (color_code == 3)
        *pixel = 0x0000FF;  // Blue
    else if (color_code == 4)
        *pixel = 0xFFFF00;  // Yellow
    else if (color_code == 5)
        *pixel = 0xFF00FF;  // Magenta
    else
        *pixel = 0xFFFFFF;  // White
}
