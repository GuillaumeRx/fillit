/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_of_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:59:05 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/14 16:47:22 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*creer un nouveau maillon a chaque fois*/

int	part_of_list(t_piece **pieces)
{
	t_piece	*cur;

	if (*pieces)
	{
		if (!(cur = (t_piece *)malloc(sizeof(t_piece))))
			return (0);
		cur->next = NULL;
		(*pieces)->next = cur;
	}
	else
	{
		if (!(cur = (t_piece *)malloc(sizeof(t_piece))))
			return (0);
		(*pieces)->next = NULL;
	}
	return (1);
}
