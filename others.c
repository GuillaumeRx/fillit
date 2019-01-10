/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:12:23 by guroux            #+#    #+#             */
/*   Updated: 2019/01/10 21:02:12 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i < 147483647)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (0);
}

int			get_size(t_piece **start)
{
	int 	piece_nbr;
	t_piece *tmp;

	tmp = *start;
	piece_nbr = 0;
	while (tmp)
	{
		tmp = tmp->next;
		piece_nbr++;
	}
	return (ft_sqrt(piece_nbr * 4));
}
