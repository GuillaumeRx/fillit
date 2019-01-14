/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_of_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:59:05 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/14 17:34:51 by cduverge         ###   ########.fr       */
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

/*passer les donnees du **board dans une liste chainee*/

int	convert_board_into_block_list(t_piece **pieces)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			while ((*pieces)->board[i][j] == '.')
				j++;
			if ((*pieces)->board[i][j] == '#')
			{
				
				(*pieces)->pos = get_pos(pieces->pos);
			}
			j++;
		}
		i++;
	}
}

t_block	*get_pos(s_block *pos)
{
	t_block	*cur;

	if (!())
}
