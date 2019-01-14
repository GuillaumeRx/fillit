/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_or_invalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:37:12 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/14 16:46:55 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*verifier le nombre de # dans un tableau*/

int	check_block_number(char board[5][5])
{
	int	ret;
	int	i;
	int	j;

	i = 0;
	ret = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			while (board[i][j] == '.')
				j++;
			if (board[i][j] == '#')
				ret++;
			j++;
		}
		i++;
	}
	if (ret != 4)
		return (0);
	return (1);
}

/*vertifier le nombre de contacts entre les carres d'un tetromino*/

int	check_positions(int i, int j, char board[5][5])
{
	int	ret;

	ret = 0;
	if (board[i][j - 1] == '#')
		ret++;
	if (board[i - 1][j] == '#')
		ret++;
	if (board[i + 1][j] == '#')
		ret++;
	if (board[i][j + 1] == '#')
		ret++;
	return (ret);
}

/*verifier si la ligne contient les caracteres valides*/

int	valid_or_invalid(char *line)
{
	int i;

	i = 0;
	if (ft_strlen(line) == 4)
	{
		while (i < 4 && (line[i] == '.' ||  line[i] == '#'))
			i++;
		if (i != 4)
			return (0);
		if (line[i] != '\0')
			return (0);
		return (1);
	}
	else if (ft_strlen(line) == 1)
	{
		if (line[0] != '\n')
			return (0);
		return (1);
	}
	return (0);
}

/*verifier que l'agencement des caracteres lus correcpond bien a celui d'un
 * tetromino valide*/

int	v_or_invalid_piece(char board[5][5])
{
	int		i;
	int		j;
	int		ret;

	if (!(check_block_number(board)))
		return (0);
	i = 0;
	ret = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			while (board[i][j] == '.')
				j++;
			if (board[i][j] == '#')
				ret = ret + check_positions(i, j, board);
			j++;
		}
		i++;
	}
	if (ret == 6 || ret == 8)
		return (1);
	return (0);
}
