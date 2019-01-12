/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:52:30 by guroux            #+#    #+#             */
/*   Updated: 2019/01/12 02:47:02 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		piece_is_placable(t_block *block, char **board, int x, int y, int size)
{
	x += block->x;
	y += block->y;
	if (y >= size || x >= size)
		return (0);
	if (board[y][x] == '.')
	{
		if(block->next == NULL)
			return (1);
		return (piece_is_placable(block->next, board, x, y, size));
	}
	else
		return (0);
}

int				fillit(t_piece *actual, char **board, int size, char letter)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < size)
	{
		printf("im on %d y\n", y);
		while (x < size)
		{
			printf("im on %d x\n", x);
			if (piece_is_placable(actual->pos, board, x, y, size))
			{
					printf("piece is placable\n");
					write_piece(actual->pos, board, x, y, letter);
					printf("piece placed\n----------------------------\n");
					if (actual->next == NULL)
						return (1);
					else if (fillit(actual->next, board, size, letter = letter + 1))
						return (1);
					else
						delete_piece(actual->pos, board, x, y);
			}
			printf("piece is not placable\n");
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
