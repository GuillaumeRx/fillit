/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:38:28 by guroux            #+#    #+#             */
/*   Updated: 2019/01/08 13:23:33 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define USAGE "usage : ./fillit file"

#include <fcntl.h>
#include "get_next_line.h"

int		check_error(int fd);
/* je ne sais pas si on a droit aux structures je ne vois rien dans le sujet
 * qui l'interdit d'une quelconque maniere mais celle qui suit est prevue
 * pour checker les erreurs a la lecture du fichier*/
typedef struct	s_error {

	int	i;
	int	j;
	int	k;
	int	end;
}				t_error;

#endif
