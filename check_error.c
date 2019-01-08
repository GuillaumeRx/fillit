/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:26:04 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/08 17:33:33 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*0 = Faux ou erreur \ 1 = Vrai*/

#include "fillit.h"

static int	read_a_piece(int fd, t_piece *pieces, char *line)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	if (pieces.next)
		pieces.next = pieces;
	else
		pieces.next = NULL;
	while (i < 4)
	{ /*gros pb a gerer --> gnl ne peut pas renvoyer 0 car il ne doit ici lire
		qu un tetrimino or le fichier en contient plusieurs --> a corriger 
		demain*/
		if ((ret = get_next_line(fd, &line)) == -1)
			return (0);
		else if (ret == 0)
			return (1);
		j = 0;
		while (line[j] == '.' || line[j] == '#')
		{
			board[i][j] = line[j];
			j++;
		}
		if (j != 4 && line[j] != '\n')
			return (0);
		board[i][j] = '\0';
		i++;
	}
}

int			check_error(int fd)
{
	t_piece	*pieces;
	int		ret;
	int		max_piece;
	char	*line;

	if (fd < 0)
		return (0);
	if (!(*pieces = (t_piece *)malloc(sizeof(t_piece))))
		return (0);
	max_piece = 0;
	while (max_piece < 26)
	{
		if (read_a_piece(fd, *pieces, line) == 0)
			return (0);
		max_piece++;
	}
	return (1);
}
