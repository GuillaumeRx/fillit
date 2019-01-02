/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:35:12 by guroux            #+#    #+#             */
/*   Updated: 2018/11/15 19:43:10 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	int		lng;

	i = 0;
	j = 0;
	lng = ft_strlen(needle);
	if (lng == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (j == lng - 1)
				return ((char *)(haystack + i));
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
