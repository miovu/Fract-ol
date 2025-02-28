/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:09:41 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/02/27 23:48:00 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//header

#include "../fract_ol.h"

//esta função serve para fazer a escala de valores = [0--799] -> [-2..+2]
//linear interpolation ----VER O QUE É------
double  map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    //double old_min = 0; ---- norminette, depois podes tirar este parametro e trocar por 0
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

//somar os números complexos, adição de vetores
//z costuma ser utilizado para representar valores complexos
t_complex   sum_complex(t_complex z1, t_complex z2)
{
    t_complex   result;
    
    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return (result);
}

//square a number
// real = (x^2 - y^2)
// imaginary = 2*x*y
t_complex   square_complex(t_complex z)
{
    t_complex   result;
    
    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return (result);
}
