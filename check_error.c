/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:26:04 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/08 15:11:44 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*s'occuper des gestions d'erreur*/
int	check_error(int fd)
{
	int		ret;
	t_error	*cur;
	char	*line;
	int		ret;

	if (!(*cur = (t_error *)malloc(sizeof(t_error))))
		return (-1);
	cur.i = 0;
	while (cur.i < 26)
	{
		cur.j = 0;
		while (cur.j < 4)
		{
			if (get_next_line(fd, &line) == -1)
				return (-1);
			if ((cur.end = ft_strlen(line)) != 5)
				return (-1);
			cur.k = 0;
			while (line[cur.k] == '.' || line[cur.k] == '#')
				cur.k++;
			if (cur.k != cur.end && line[cur.k] != '\n')
				return (-1);
			else
				j++;
		}
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (-1);
		else if (ret == 1)
		{
			if (line[0] != '\n')
				return (-1);
			i++;
		}
		return (0);
	}
	return (0);
}
