/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:11:50 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/10 17:34:50 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_piece	*pieces;
	int	fd;

	if (ac != 2)
		ft_putendl(USAGE);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (check_error(fd, *pieces) == 0)
		{
			ft_putendl("error");
			return(-1);
		}
	}
		/* traiter les info et checker les erreurs */
	return (0);
}
