/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:45:25 by guroux            #+#    #+#             */
/*   Updated: 2019/01/11 02:43:52 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	create_block_list(t_block **block, int i)
{
	t_block *actual;

	actual = (t_block *)malloc(sizeof(t_block));
	if (i == 0)
	{
		printf("block created\n");
		(*actual).x = 0;
		(*actual).y = 0;
		printf("actual y :%d\n", actual->y);
		create_block_list(&(actual->next), i = i + 1);
	}
	else if (i < 3)
	{
		printf("block created\n");
		(*actual).x = 0;
		(*actual).y = 1;
		printf("actual y :%d\n", actual->y);
		create_block_list(&((*actual).next), i = i + 1);
	}
	else if (i == 3)
	{
		printf("last block created\n");
		*block = actual;
		(*actual).x = 0;
		(*actual).y = 1;
		printf("actual y :%d\n", actual->y);
		(*block)->next = NULL;
	}
}

void	lstadd(t_piece **alst)
{
	t_piece *new;

	printf("tetrimino created\n");
	new = (t_piece *)malloc(sizeof(t_piece));
	create_block_list(&(new->pos), 0);
	if (alst)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_piece		*lstnew()
{
	t_piece	*list;

	if (!(list = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL); 
	list->next = NULL;
	return (list);
}

void	create_piece_list(t_piece **list)
{
	int		i;
	i = 0;
	while (i < 3)
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

	start = lstnew();
	create_piece_list(&start);
	printf("Done with tertriminos creation\n");
	size = get_size(start);
	printf("size of board is %d\n", size);
	board = init_board(&start);
	printf("Done with board creation\n");
	fillit(start, board, size, 'A');
	display_board(board);
}
