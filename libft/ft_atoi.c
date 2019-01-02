/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 20:51:29 by guroux            #+#    #+#             */
/*   Updated: 2018/11/15 21:51:05 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			n;
	long long	tmp;
	int			i;

	n = 1;
	i = 0;
	tmp = 0;
	while (str[i] == '\f' || str[i] == '\r' || str[i] == '\n' || str[i] == '\v'
	|| str[i] == '\t' || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (ft_isdigit((int)str[i]))
	{
		tmp = tmp * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(tmp * n));
}
