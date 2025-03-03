/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:17:12 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/03/03 15:12:00 by miovu            ###   ########.fr       */
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
    
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return (result);
}

t_complex   square(t_complex z)
{
    t_complex   result;
    
    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return (result);
}
