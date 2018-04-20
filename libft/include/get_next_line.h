/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:41:43 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/07 13:22:28 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# define BUFF_SIZE 11
# define CHAR '\n'

typedef struct	s_b
{
	char	*first;
	int		ret2;
}				t_b;

int				get_next_line(const int fd, char **line);

#endif
