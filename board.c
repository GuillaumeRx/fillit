/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:10:10 by guroux            #+#    #+#             */
/*   Updated: 2019/01/12 02:56:48 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	write_piece(t_block *block,char **board, int x, int y, char letter)
{
	x = x + block->x;
	y = y + block->y;
	board[y][x] = letter;
	if (block->next != NULL)
		write_piece(block->next, board, x, y, letter);
}

void		delete_piece(t_block *block,char **board, int x, int y)
{
	x = x + block->x;
	y = y + block->y;
	board[y][x] = '.';
	if (block->next != NULL)
		delete_piece(block->next, board, x, y);
}

char		**init_board(int size)
{
	char	**board;
	int		i;
	int		j;

	i = 0;
	if (!(board = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (i < size)
	{
		if (!(board[i] = (char *)malloc(sizeof(char) * size + 1)))
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
	return(board);
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
