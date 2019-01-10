/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:26:04 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/10 17:34:22 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*0 = Faux ou erreur \ 1 = Vrai*/

#include "fillit.h"

int	check_each_error(int fd, t_piece **pieces)
{
	if (!(part_of_list(pieces)))
		return (0);
	if (!(ret = read_pieces(fd, *pieces->board)))
		return (0);
	if (!(v_or_invalid_piece(*pieces->board)))
		return (0);
	return (1);
}

/*lire ligne par ligne les pieces du fichier et les verifier en meme temps*/

int	read_pieces(int fd, char board[5][5])
{
	int		ret;
	int		i;
	int		j;
	char	*line;

	line = "";
	i = 0;
	while (i < 4)
	{
		if ((ret = get_next_line(fd, &line)) < 0)
			return (0);
		if (!(valid_or_invalid_(line)))
			return (0);
		j = 0;
		while (j < 4)
		{
			board[i][j] = line[j];
			j++;
		}
		board[i][j] = line[j];
		i++;
	}
	return (1);
}

/*remonter l'ensemble des erreurs verifiees et s'assurer qu'on a un 
 * nombre valide de tetrominos*/

int	check_error(int fd, t_piece **pieces)
{
	int		ret;
	int		max_piece;
	char	*line;
	t_piece	*cur;

	cur = *pieces;
	line = "";
	if (fd < 0)
		return (0);
	max_piece = 0;
	while (max_piece < 26)
	{
		if (check_each_error(fd, *cur))
			return (0);
		if ((ret = get_next_line(fd, &line) < 0))
			return (0);
		free(line);
		else if (ret == 0)
		{
			free(cur);
			return (1);
		}
		if (!(valid_or_invalid(line)))
			return (0);
		max_piece++;
		cur = *pieces->next;
	}
	return (0);
}
