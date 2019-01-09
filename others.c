/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:12:23 by guroux            #+#    #+#             */
/*   Updated: 2019/01/09 20:13:28 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static		ft_sqrt(int nb)
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
	while (tmp)
	{
		tmp = tmp->next;
		piece_nbr++;
	}
	return (ft_sqrt(piece_nbr * 4));
}
