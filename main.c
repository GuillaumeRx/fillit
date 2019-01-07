/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:11:50 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/07 17:31:18 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		ft_putendl(USAGE);
	else
		fd = open(av[1], O_RDONLY);
		/* traiter les info et checker les erreurs */
	return (0);
}
