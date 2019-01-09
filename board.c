/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:10:10 by guroux            #+#    #+#             */
/*   Updated: 2019/01/09 20:11:00 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		write_piece(t_block *block,char **board, int pos[2], char letter)
{
	pos[0] =+ block->x;
	pos[1] =+ block->y;
	board[pos[1]][pos[0]] = letter;
	if (block->next != NULL)
		write_piece(block->next, board, pos, letter);
}

void		delete_piece(t_block *block,char **board, int pos[2])
{
	pos[0] =+ block->x;
	pos[1] =+ block->y;
	board[pos[1]][pos[0]] = '.';
	if (block->next != NULL)
		delete_piece(block->next, board, pos);
}

/* 	Initialization of the final board using a simple algorithm :
	board_size = sqrt( number of tetriminos * number of blocks of a tetriminos (4) )
	Than malloc a double char tab wich is used to represent the board.
*/
char		**init_board(t_piece **start)
{
	char	**board;
	int		size;
	int		i;
	int		j;

	i = 0;
	size = get_size(*start);
	if (!(board = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (i++ < size)
	{
		if (!(board[i] = (char *)malloc(sizeof(char) * size + 1)))
		{
			free(board);
			return (NULL);
		}
		j = 0;
		while (j++ < size)
			board[i][j] = '.';
		board[i][j] = '\0';
	}
	board[size] = NULL;
	return(board);
}
