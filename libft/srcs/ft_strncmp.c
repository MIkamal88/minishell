/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:58:53 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/15 10:23:19 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

// int	main(void)
// {
// 	printf("%d", ft_strncmp("test\200", "test\0", 6));
// }
	// size_t	i;

	// i = 0;
	// if (n == 0)
	// 	return (0);
	// while (i < n)
	// {
	// 	if (s1[i] != s2[i])
	// 		return (s1[i] - s2[i]);
	// 	else if (s1[i] == '\0' && s2[i] == '\0')
	// 		return (0);
	// 	i++;
	// }
	// return (s1[i] - s2[i]);
