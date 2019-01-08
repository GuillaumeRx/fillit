/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:52:30 by guroux            #+#    #+#             */
/*   Updated: 2019/01/08 19:23:57 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
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

/* Doing the placing function, need to implement backtracking while documenting on the subject */
void	fillit(t_piece **start, char **board)
{
	t_piece		*piece;
	int			i;
	int			j;
	while ((*(piece)->board[i++]) != NULL)
	{
		while ((piece->board[i++][j++]) != '\0')
		{
			if ((piece->board[i++][j++]) == '#')
				board[i][j] == (piece->board[i++][j++]);
		}
	}
}

/* 	Initialization of the final board using a simple algorithm :
	board_size = sqrt( number of tetriminos * number of blocks of a tetriminos (4) )
	Than malloc a double char tab wich is used to represent the board.
*/
char	**init_board(t_piece **start)
{
	t_piece *tmp;
	char	**board;
	int 	piece_nbr;
	int		size;
	int		i;
	int		j;

	i = 0;
	tmp = *start;
	while (tmp)
	{
		tmp = tmp->next;
		piece_nbr++;
	}
	size = ft_sqrt(piece_nbr * 4);
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
