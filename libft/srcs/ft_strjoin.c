/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:05:31 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/15 10:23:06 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	char	*str;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[k++] = s1[i++];
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		str[k++] = s2[i++];
	}
	str[k] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	*s1 = "This is a ";
// 	char	*s2 = "test phrase";
// 	printf("%s\n", ft_strjoin(s1, s2));
// }
