/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:12:23 by guroux            #+#    #+#             */
/*   Updated: 2019/01/11 02:11:23 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i < 147483647)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (0);
}

int get_size(t_piece *head) 
{ 
    int count;
	
	count = 0; 
    t_piece *current = head; 
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    }
    return (ft_sqrt(count * 4));
} 
