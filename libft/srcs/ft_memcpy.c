/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:10:58 by mshehata          #+#    #+#             */
/*   Updated: 2022/11/25 09:42:53 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dstc;
	unsigned char	*srcc;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	while (i < n)
	{
		dstc[i] = srcc[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	src[] = "test phrase123";
// 	char	dest[100];
// 	char	*dest_ptr = ft_memcpy(dest, src, 16);

// 	printf("src: %s\n", src);
// 	printf("dest: %s\n", dest);
// 	printf("dest_ptr: %p\n", dest_ptr);
// 	printf("dest: %p\n", dest);
// }
