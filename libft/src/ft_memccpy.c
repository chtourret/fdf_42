/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:04:20 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/13 15:02:09 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*str1;
	const char	*str2;

	i = 0;
	str1 = dst;
	str2 = src;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == (char)c)
			return ((void *)&str1[i + 1]);
		i++;
	}
	return (NULL);
}
