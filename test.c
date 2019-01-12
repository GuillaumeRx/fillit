/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:45:25 by guroux            #+#    #+#             */
/*   Updated: 2019/01/12 03:09:52 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block 	*create_block_list(int i)
{
	t_block *actual;

	actual = (t_block *)malloc(sizeof(t_block));
	if (i == 0)
	{
		printf("block created\n");
		(*actual).x = 0;
		(*actual).y = 0;
		printf("actual y :%d\n", actual->y);
		actual->next = create_block_list(i = i + 1);
	}
	else if (i < 3)
	{
		printf("block created\n");
		(*actual).x = 0;
		(*actual).y = 1;
		printf("actual y :%d\n", actual->y);
		actual->next = create_block_list(i = i + 1);
	}
	else if (i == 3)
	{
		printf("last block created\n");
		(*actual).x = -1;
		(*actual).y = 0;
		printf("actual y :%d\n", actual->y);
		actual->next = NULL;
	}
	return(actual);
}

t_block	*create_block()
{
	t_block *block;

	block = (t_block *)malloc(sizeof(t_block));
	block->x = 0;
	block->y = 0;
	block->next = NULL;
	return (block);
}

void	lstadd(t_piece **alst)
{
	t_piece *new;

	printf("tetrimino created\n");
	new = (t_piece *)malloc(sizeof(t_piece));
	new->pos = create_block_list(0);
	if (alst)
	{
	new->next = *alst;
	*alst = new;
	}
	else 
	{
		new->next = NULL;
		*alst = new;

	}
}

void	create_piece_list(t_piece **list)
{
	int		i;
	i = 0;
	while (i < 4)
	{
		lstadd(list);
		printf("Tetrimino number %d created\n", i);
		i++;	
	}
}

int		main(void)
{
	t_piece *start;
	char	**board;
	int		size;
	int		pos[2];

	pos[0] = 0;
	pos[1] = 0;
	create_piece_list(&start);
	printf("Done with tertriminos creation\n");
	size = get_size(start);
	printf("size of board is %d\n", size);
	board = init_board(size);
	printf("Done with board creation\n--------------------------------------------------------------------------------------\n");
	while (!(fillit(start, board, size, 'A')))
	{
		free(board);
		size++;
		board = init_board(size);
	}
	display_board(board);
}
