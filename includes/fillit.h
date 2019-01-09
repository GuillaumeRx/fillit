/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:38:28 by guroux            #+#    #+#             */
/*   Updated: 2019/01/09 16:42:50 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define USAGE "usage : ./fillit file"

#include <fcntl.h>
#include "get_next_line.h"

typedef struct		s_piece {
	char			board[5][5];
	struct s_block	*pos;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_block{
	int				x;
	int				y;
	struct s_block	*next;
}					t_block;

#endif
