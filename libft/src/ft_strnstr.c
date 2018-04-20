/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:58:05 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/13 15:07:16 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*p1;
	char	*p2;
	size_t	len2;

	len2 = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big && len >= len2)
	{
		p1 = (char *)big;
		p2 = (char *)little;
		if (ft_strncmp(p1, p2, len2) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
