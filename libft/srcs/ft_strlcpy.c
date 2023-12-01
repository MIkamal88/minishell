/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_strlcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:02:54 by mshehata          #+#    #+#             */
/*   Updated: 2022/11/10 14:45:43 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	*dst;

// 	if (!(dst = (char *)malloc(sizeof(*dst) * 15)))
// 		return (0);
// 	memset(dst, 0, 15);
// 	memset(dst, 'r', 6);
// 	printf("%lu\n", ft_strlcpy(dst, "lorem ipsum", 3));
// 	printf("%s\n", dst);
// }
