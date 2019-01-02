/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:08:04 by guroux            #+#    #+#             */
/*   Updated: 2018/11/13 21:09:28 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int f_num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	f_num = n;
	if (f_num >= 10)
	{
		ft_putnbr_fd(f_num / 10, fd);
		ft_putnbr_fd(f_num % 10, fd);
	}
	else
	{
		ft_putchar_fd(f_num + '0', fd);
	}
}
