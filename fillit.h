/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:38:28 by guroux            #+#    #+#             */
/*   Updated: 2019/01/18 22:42:28 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define USAGE "usage : ./fillit file"

# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

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

int					read_pieces(int fd, char board[5][5]);
int					do_tetrimino(t_piece **cur, int fd);
int					check_empty_line(int fd);
int					check_error(int fd, t_piece **pieces, int max_piece);
int					check_block_number(char board[5][5]);
int					check_positions(int i, int j, char board[5][5]);
int					valid_or_invalid(char *line);
int					validate_empty_line(char *line);
int					v_or_invalid_piece(char board[5][5]);
int					fd_other_block(char board[5][5], int i, int j,
t_block **cur);
int					search_first_block(char board[5][5], t_block **cur);
int					convert_board_into_block_list(t_piece **pieces);
int					piece_is_placable(t_block *block, char **board,
int pos[2], int size);
int					backtrack(t_piece *actual, char **board, int size,
char letter);
int					fillit(int fd, t_piece **start);
void				write_piece(t_block *block, char **board, int pos[2],
char letter);
void				delete_piece(t_block *block, char **board, int pos[2]);
char				**init_board(int size);
void				display_board(char **board);
void				free_board(char **board);
int					get_size(t_piece *head);
void				free_piece(t_piece **piece);
void				free_block(t_block **block);

#endif
