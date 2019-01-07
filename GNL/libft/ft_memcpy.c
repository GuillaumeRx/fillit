/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:53:55 by cduverge          #+#    #+#             */
/*   Updated: 2018/11/30 14:16:25 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	unsigned int	i;
	char			*dest1;
	char			*src1;

	i = 0;
	dest1 = (char *)dest;
	src1 = (char *)src;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	dest = dest1;
	return (dest);
}
