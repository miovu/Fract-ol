/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:11:24 by miovu             #+#    #+#             */
/*   Updated: 2025/03/10 12:30:40 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

double  scale(double unscaled_num, double new_min, double new_max, double old_max)
{
    return (new_max - new_min) * (unscaled_num / old_max) + new_min;
}

t_complex   sum(t_complex a, t_complex b)
{
    t_complex   result;
    
    result.real = a.real + b.real;
    result.im = a.im + b.im;
    return (result);
}

t_complex   square(t_complex z)
{
    t_complex   result;
    
    result.real = (z.real * z.real) - (z.im * z.im);
    result.im = 2 * z.real * z.im;
    return (result);
}
