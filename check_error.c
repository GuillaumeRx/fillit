/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:26:04 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/18 22:43:09 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	read_pieces(int fd, char board[5][5])
{
	int		ret;
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < 4)
	{
		if ((ret = get_next_line(fd, &line)) <= 0)
			return (0);
		if (!(valid_or_invalid(line)))
			return (0);
		j = 0;
		while (j < 4)
		{
			board[i][j] = line[j];
			j++;
		}
		board[i][j] = '\0';
		i++;
		if (ret == 1)
			free(line);
	}
	return (1);
}

int	do_tetrimino(t_piece **cur, int fd)
{
	int ret;

	if (!((*cur) = (t_piece *)malloc(sizeof(t_piece))))
		return (0);
	(*cur)->pos = NULL;
	if ((ret = read_pieces(fd, (*cur)->board)) <= 0)
		return (0);
	if (ret == 2)
		return (2);
	if (!(v_or_invalid_piece((*cur)->board)))
		return (0);
	(*cur)->next = NULL;
	return (1);
}

int	check_empty_line(int fd)
{
	char	*line;
	int		ret;

	if (!(ret = get_next_line(fd, &line)))
		return (2);
	else if (ret < 0)
		return (0);
	if (!(validate_empty_line(line)))
		return (0);
	if (ret == 1)
		free(line);
	return (1);
}

int	check_error(int fd, t_piece **pieces, int max_piece)
{
	t_piece	*cur;
	t_piece	*tmp;
	int		ret;

	cur = *pieces;
	++max_piece;
	if (!(do_tetrimino(&(cur), fd)))
		return (0);
	if (!(ret = check_empty_line(fd)))
		return (0);
	if (ret != 2 && max_piece <= 26)
	{
		ret = check_error(fd, &(tmp), max_piece);
		if (ret)
			cur->next = tmp;
		*pieces = cur;
		return (ret);
	}
	else if (ret != 2 && max_piece > 26)
		return (0);
	*pieces = cur;
	return (1);
}
