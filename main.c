/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:11:50 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/18 23:38:22 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_piece		*pieces;
	int			fd;

	if (ac != 2)
		ft_putendl(USAGE);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (!(fillit(fd, &pieces)))
			ft_putendl("error");
		close(fd);
	}
	return (0);
}
