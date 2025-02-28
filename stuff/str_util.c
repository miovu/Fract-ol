/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:18:01 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/02/23 15:24:38 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//header

#include "../fract_ol.h"

int ft_strncmp1(char *s1, char *s2, int n)
{
    if (s1 == NULL || s2 == NULL || n <= 0)
        return (0);
    while (*s1 == *s2 && n > 0 && *s1 != '\0')
    {
        ++s1;
        ++s2;
        --n;
    }
    return (*s1 - *s2);
}

void    putstr_fd1(char *s, int fd)
{
    if (*s == NULL || fd < 0)
        return ;
    if (*s)
    {
        write (fd, s, 1);
        putstr_fd1(s + 1, fd);
    }
}
