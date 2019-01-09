/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:26:04 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/09 17:32:22 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*0 = Faux ou erreur \ 1 = Vrai*/

#include "fillit.h"

int	check_each_error(int fd, char *line, t_piece *pieces)
{
	if (!(part_of_list(pieces)))
		return (0);
	if (!(ret = read_pieces(fd, line, pieces)))
		return (0);
	if (!(v_or_invalid_piece(pieces)))
		return (0);
	return (1);
}

/*lire ligne par ligne les pieces du fichier et les verifier en meme temps*/

int	read_pieces(int fd, char *line, t_piece *pieces)
{
	int	ret;
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if ((ret = get_next_line(fd, &line)) < 0)
			return (0);
		if ((j = ft_strlen(line)) != 5)
			return (0);
		if (!(valid_or_invalid_(line)))
			return (0);
		j = 0;
		while (j < 5)
		{
			board[i][j] = line[j];
			j++;
		}
		i++;
	}
	return (1);
}

/*remonter l'ensemble des erreurs verifiees et s'assurer qu'on a un 
 * nombre valide de tetrominos*/

int	check_error(int fd)
{
	t_piece	*pieces;
	int		ret;
	int		max_piece;
	char	*line;

	if (fd < 0)
		return (0);
	max_piece = 0;
	while (max_piece < 26)
	{
		if (check_each_error(fd, l ine, pieces))
			return (0);
		if ((ret = get_next_line(fd, &line) < 0))
			return (0);
		else if (ret == 0)
		{
			free(pieces);
			return (1);
		}
		if (!(valid_or_invalid(line)))
			return (0);
		max_piece++;
	}
	return (1);
}
