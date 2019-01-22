/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:10:10 by guroux            #+#    #+#             */
/*   Updated: 2019/01/22 14:44:52 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		write_piece(t_block *block, char **board, int pos[2], char letter)
{
	int pos_next[2];
	int x;
	int y;

	x = pos[0] + block->x;
	y = pos[1] + block->y;
	board[y][x] = letter;
	pos_next[0] = x;
	pos_next[1] = y;
	if (block->next != NULL)
		write_piece(block->next, board, pos_next, letter);
}

void		delete_piece(t_block *block, char **board, int pos[2])
{
	int x;
	int y;
	int pos_next[2];

	x = pos[0] + block->x;
	y = pos[1] + block->y;
	board[y][x] = '.';
	pos_next[0] = x;
	pos_next[1] = y;
	if (block->next != NULL)
		delete_piece(block->next, board, pos_next);
}

char		**init_board(int size)
{
	char	**board;
	int		i;
	int		j;

	i = 0;
	if (!(board = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(board[i] = (char *)malloc(sizeof(char) * (size + 1))))
		{
			free(board);
			return (NULL);
		}
		j = 0;
		while (j < size)
		{
			board[i][j] = '.';
			j++;
		}
		board[i][j] = '\0';
		i++;
	}
	board[size] = NULL;
	return (board);
}

void		display_board(char **board)
{
	int i;

	i = 0;
	while (board[i] != 0)
	{
		ft_putendl(board[i]);
		i++;
	}
}

void		free_board(char **board)
{
	int i;

	i = 0;
	while (board[i] != 0)
	{
		free(board[i]);
		board[i] = NULL;
		i++;
	}
	free(board);
}
