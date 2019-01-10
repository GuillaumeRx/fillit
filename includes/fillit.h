/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:38:28 by guroux            #+#    #+#             */
/*   Updated: 2019/01/10 16:17:02 by guroux           ###   ########.fr       */
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
int	check_block_number(t_piece *pieces);
int	check_positions(int i, int j, t_piece *pieces);

/* fillit.c */
int		fillit(t_piece *actual, char **board, int size, char letter);

/* board.c */
void	write_piece(t_block *block,char **board, int pos[2], char letter);
void	delete_piece(t_block *block,char **board, int pos[2]);
char	**init_board(t_piece **start);
void	display_board(char **board);

/* others.c */
int		get_size(t_piece **start);


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
