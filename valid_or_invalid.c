/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_or_invalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:37:12 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/09 16:28:49 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*verifier si la ligne contient les caracteres valides*/

int	valid_or_invalid(char *line)
{
	int i;

	i = 0;
	if (ft_strlen(line) == 5)
	{
		while (i < 5 && (line[i] == '.' ||  line[i] == '#'))
			i++;
		if (i != 5)
			return (0);
		if (line[i] != '\0')
			return (0);
		return (1);
	}
	else if (ft_strlen(line) == 2)
	{
		if (line[0] != '\n')
			return (0);
		return (1);
	}
	return (0);
}

/*verifier que l'agencement des caracteres lus correcpond bien a celui d'un
 * tetromino valide*/

int	v_or_invalid_piece(t_piece *pieces)
{
	
}
