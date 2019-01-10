/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:26:04 by guroux            #+#    #+#             */
/*   Updated: 2019/01/10 16:38:01 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_piece(t_piece **piece)
{
	while (*piece)
	{
		free((*piece)->board);
		free_block((*piece)->pos);
		free_piece(&((*piece)->next));
		free(*piece);
		*piece = NULL;
	}
}

void		free_block(t_block **block)
{
	while (*block)
	{
		free_block(&((*block)->next));
		free(*block);
		*block = NULL;
	}
}
