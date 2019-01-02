/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:49:05 by guroux            #+#    #+#             */
/*   Updated: 2018/11/09 13:53:13 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int f_num;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	f_num = n;
	if (f_num >= 10)
	{
		ft_putnbr(f_num / 10);
		ft_putnbr(f_num % 10);
	}
	else
	{
		ft_putchar(f_num + '0');
	}
}
