/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:02:32 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/13 15:02:02 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if ((str = (void *)malloc(sizeof(*str) * size)) == NULL)
		return (NULL);
	ft_bzero(str, size);
	return ((void *)str);
}
