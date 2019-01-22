/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_or_invalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:37:12 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/22 15:34:11 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_block_number(char board[5][5])
{
	int	ret;
	int	i;
	int	j;

	i = 0;
	ret = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
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

int	check_positions(int i, int j, char board[5][5])
{
	int	ret;

	ret = 0;
	if (board[i][j - 1] && board[i][j - 1] == '#')
		ret++;
	if (board[i - 1][j] && board[i - 1][j] == '#')
		ret++;
	if (board[i + 1][j] && board[i + 1][j] == '#')
		ret++;
	if (board[i][j + 1] && board[i][j + 1] == '#')
		ret++;
	return (ret);
}

int	valid_or_invalid(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) == 4)
	{
		while (i < 4 && (line[i] == '.' || line[i] == '#'))
			i++;
		if (i != 4)
			return (0);
		if (line[i] != '\0')
			return (0);
		return (1);
	}
	return (0);
}

int	validate_empty_line(char *line)
{
	if (ft_strlen(line) == 0)
	{
		if (line[0] != '\0')
			return (0);
		return (1);
	}
	return (0);
}

int	v_or_invalid_piece(char board[5][5])
{
	int	i;
	int	j;
	int	ret;

	if (!(check_block_number(board)))
		return (0);
	i = 0;
	ret = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
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
