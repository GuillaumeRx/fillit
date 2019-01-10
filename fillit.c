/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:52:30 by guroux            #+#    #+#             */
/*   Updated: 2019/01/10 16:10:41 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		piece_is_placable(t_block *block, char **board, int pos[2], int size)
{
	int x;
	int y;

	if ((pos[0] =+ block->x) >= size || (pos[1] =+ block->y) >= size)
		return (0);
	if (board[pos[1]][pos[0]] == '.')
	{
		if(block->next == NULL)
			return (1);
		return (piece_is_placable(block->next, board, pos, size));
	}
	else
		return (0);
}

int				fillit(t_piece *actual, char **board, int size, char letter)
{
	int		size;
	int		pos[2];

	pos[0] = 0;
	pos[1] = 0;
	while (pos[1] < size)
	{
		while (pos[0] < size)
		{
			if (piece_is_placable(actual->pos, board, pos, size))
			{
					write_piece(actual->pos, board, pos, letter);
					if (fillit(actual->next, board, size, letter++) || actual->next == NULL)
						return (1);
					else
						delete_piece(actual->pos, board, pos);
			}
			pos[0]++;
		}
		pos[1]++;
	}
	return (0);
}
