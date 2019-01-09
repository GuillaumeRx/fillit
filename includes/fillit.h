/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:38:28 by guroux            #+#    #+#             */
/*   Updated: 2019/01/09 19:54:46 by guroux           ###   ########.fr       */
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

/* fillit.c */

int		get_size(t_piece *start);
int		piece_is_placable(t_block *block, char **board, int pos[2], int size);
int		is_valid(t_piece **start, char **board);

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
