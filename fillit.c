/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:52:30 by guroux            #+#    #+#             */
/*   Updated: 2019/01/18 20:04:13 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		piece_is_placable(t_block *block, char **board, char pos[2], int size)
{
	int x;
	int y;
	int	pos_next[2];

	x = pos[0] + block->x;
	y = pos[1] + block->y;
	if (y >= size || x >= size)
		return (0);
	if (board[y][x] == '.')
	{
		if(block->next == NULL)
			return (1);
		pos_next[0] = x;
		pos_next[1] = y;
		return (piece_is_placable(block->next, board, pos_next, size));
	}
	else
		return (0);
}

int				backtrack(t_piece *actual, char **board, int size, char letter)
{
	int		pos[2];

	pos[0] = 0;
	pos[1] = 0;
	letter++;
	while (pos[1] < size)
	{
		while (pos[0] < size)
		{
			if (piece_is_placable(actual->pos, board, pos, size))
			{
					write_piece(actual->pos, board, pos, letter);
					if (actual->next == NULL)
						return (1);
					else if (backtrack(actual->next, board, size, letter))
						return (1);
					else
						delete_piece(actual->pos, board, pos);
			}
			pos[0]++;
		}
		pos[0] = 0;
		pos[1]++;
	}
	return (0);
}

int		fillit(int fd, t_piece **start)
{
	char	**board;
	int		size;

	if (!(check_error(fd, start, 0)))
	{
		free_piece(start);
		return (0);
	}
	if (!(convert_board_into_block_list(start)))
	{
		free_piece(start);
		return (0);
	}
	size = get_size(*start);
	board = init_board(size);
	while (!(backtrack(*start, board, size, 64)))
	{
		free_board(board);
		size++;
		board = init_board(size);
	}
	display_board(board);
	free_piece(start);
	free_board(board);
	return (1);
}
