/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:11:50 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/07 17:20:11 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		ft_putstr(""); //mettre l'usage
	fd = open(av[1], O_RDONLY);
	// traiter les info et checker les erreurs
	return (0);
}
