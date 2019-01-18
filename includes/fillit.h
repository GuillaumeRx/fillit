/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:38:28 by guroux            #+#    #+#             */
/*   Updated: 2019/01/18 18:05:14 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define USAGE "usage : ./fillit file"

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	read_pieces(int fd, char board[5][5]);
int	do_tetrimino(t_piece **cur, int fd);
int	check_empty_line(int fd);
int	check_error(int fd, t_piece **pieces, int max_piece);
int	check_block_number(char board[5][5]);
int	check_positions(int i, int j, char board[5][5]);
int	valid_or_invalid(char *line);
int	v_or_invalid_piece(char board[5][5]);
int	fd_other_block(char board[5][5], int i, int j, t_block **cur);
int	search_first_block(char board[5][5], t_block **cur);
int	convert_board_into_block_list(t_piece **pieces);

/* fillit.c */
int		fillit(t_piece *actual, char **board, int size);

/* board.c */
void	write_piece(t_block *block,char **board, int pos[2], char letter);
void	delete_piece(t_block *block,char **board, int pos[2]);
char	**init_board(t_piece **start);

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

// int	valid_or_invalid(char *line);
// int	v_or_invalid_piece(t_piece *pieces);
// int	part_of_list(t_piece *pieces);
// int	read_pieces(int fd, char *line, t_piece *pieces);
// int	check_error(int fd);
// int	check_each_error(void);
// int	check_block_number(t_piece *pieces);
// int	check_positions(int i, int j, t_piece *pieces);

/* fillit.c */
int		piece_is_placable(t_block *block, char **board, int x, int y, int size);
int		fillit(t_piece *actual, char **board, int size, char letter);

/* board.c */
void	write_piece(t_block *block, char **board, int x, int y, char letter);
void	delete_piece(t_block *block, char **board, int x, int y);
char	**init_board(int size);
void	display_board(char **board);

/* others.c */
int		get_size(t_piece *head);


#endif
