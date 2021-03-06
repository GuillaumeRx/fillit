/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:49:41 by cduverge          #+#    #+#             */
/*   Updated: 2019/01/18 21:49:56 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE 6

int				get_next_line(const int fd, char **line);

typedef struct	s_save {

	char			*str;
	int				fd;
	struct s_save	*next;
}				t_save;

#endif
