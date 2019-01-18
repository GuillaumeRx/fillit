/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_board_into_block_list.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:31:03 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/18 17:42:43 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fd_other_block(char board[5][5], int i, int j, t_block **cur)
{
	int	i_bis;
	int	j_bis;

	i_bis = i;
	j_bis = j - 1;
	while(i < 4)
	{
		while (j < 4)
		{
			if (board[i][j] == '#')
			{
				if (!((*cur) = (t_block *)malloc(sizeof(t_block))))
					return (0);
				(*cur)->x = j - j_bis;
				(*cur)->y = i - i_bis;
				(*cur)->next = NULL;
				return (fd_other_block(board, i, j + 1, &((*cur)->next)));
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	search_first_block(char board[5][5], t_block **cur)
{
	int	j;
	int	i;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (board[i][j] == '#')
			{
				if (!((*cur) = (t_block *)malloc(sizeof(t_block))))
					return (0);
				(*cur)->x = 0;
				(*cur)->y = 0;
				return (fd_other_block(board, i, j + 1, &((*cur)->next)));
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	convert_board_into_block_list(t_piece **pieces)
{
	t_block	*cur;

	cur = (*pieces)->pos;
	if (!(search_first_bloc	k((*pieces)->board, &cur)))
		return (0);
	(*pieces)->pos = cur;
	if ((*pieces)->next != NULL)
		return (convert_board_into_block_list(&((*pieces)->next)));
	return (1);
}
