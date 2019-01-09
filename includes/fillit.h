/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:38:28 by guroux            #+#    #+#             */
/*   Updated: 2019/01/09 16:28:38 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define USAGE "usage : ./fillit file"

#include <fcntl.h>
#include "get_next_line.h"

int	valid_or_invalid(char *line);
int	v_or_invalid_piece(t_piece *pieces);
int	part_of_list(t_piece *pieces);
int	read_pieces(int fd, char *line, t_piece *pieces);
int	check_error(int fd);
int	check_each_error(void);

typedef struct		s_piece {
	char			board[5][5];
	struct s_piece	*next;
}					t_piece;

#endif
