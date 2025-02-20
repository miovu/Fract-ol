/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:25:18 by chillhoneyy       #+#    #+#             */
/*   Updated: 2024/11/18 18:31:55 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((str1[i] || str2[i]) && (i < n))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

/* #include <stdio.h>
int	main()
{
	const char	*str1 = "Hello";
	const char	*str2 = "HeLlo";
	size_t		i = 5;
	int			j;
	
	j = ft_strncmp(str1, str2, i);
	printf("Result: %d\n", j);
	return (0);
} */