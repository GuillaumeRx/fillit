/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:36:55 by guroux            #+#    #+#             */
/*   Updated: 2018/11/20 12:08:43 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *new;
	t_list *actual;

	if (!lst || !f)
		return (NULL);
	start = NULL;
	while (lst)
	{
		new = f(lst);
		if (start)
		{
			actual->next = new;
			actual = actual->next;
		}
		else
		{
			start = new;
			actual = start;
		}
		lst = lst->next;
	}
	return (start);
}
