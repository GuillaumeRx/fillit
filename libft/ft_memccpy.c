/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:23:12 by guroux            #+#    #+#             */
/*   Updated: 2018/11/17 18:48:56 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int						i;
	unsigned char			*pdst;
	const unsigned char		*psrc;

	i = 0;
	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	while (n--)
	{
		pdst[i] = psrc[i];
		if (psrc[i] == (unsigned char)c)
			return (dst + (i + 1));
		i++;
	}
	return (NULL);
}
