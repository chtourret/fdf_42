/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:19:26 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/13 15:08:20 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((str = (char *)malloc(sizeof(*str) * size + 1)) == NULL)
		return (NULL);
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
