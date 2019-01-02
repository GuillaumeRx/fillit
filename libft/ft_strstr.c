/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:13:37 by guroux            #+#    #+#             */
/*   Updated: 2018/11/15 19:33:33 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int lng;

	i = 0;
	j = 0;
	lng = ft_strlen(needle);
	if (lng == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		while (haystack[i + j] == needle[j])
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
