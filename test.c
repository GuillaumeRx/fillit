/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:45:25 by guroux            #+#    #+#             */
/*   Updated: 2019/01/10 20:56:24 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	create_block_list(t_block **block, int i)
{
	t_block *actual;

	actual = (t_block *)malloc(sizeof(t_block));
	if (i < 3)
	{
		(*actual).x = 0;
		(*actual).y = 1;
		create_block_list(&((*actual).next), i++);
	}
	else if (i == 3)
	{
		*block = actual;
		(*actual).x = 0;
		(*actual).y = 0;
		(*block)->next = NULL;
	}
}

void	create_piece_list(t_piece **list)
{
	int		i;
	t_piece *actual;

	i = 0;
	while (i < 4)
	{
		actual = (t_piece *)malloc(sizeof(t_piece));
		create_block_list(&((*actual).pos), 0);
		if (*list)
			(*list)->next = actual;
		else
		{
			*list = actual;
			(*list)->next = NULL;
		}
	}
}

int		main(void)
{
	t_piece *start;
	char	**board;
	int		size;

	create_piece_list(&start);
	size = get_size(&start);
	board = init_board(&start);

	fillit(start, board, size, 'A');
}
