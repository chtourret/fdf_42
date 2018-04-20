/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:58:23 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/13 15:07:51 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s)
{
	char		*res;
	char const	*end;
	char const	*start;

	start = NULL;
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (!(*s == ' ' || *s == '\n' || *s == '\t'))
		{
			start = (start == NULL) ? s : start;
			end = s;
		}
		s++;
	}
	if (start == NULL)
		return (ft_strnew(1));
	if ((res = (char *)malloc(sizeof(char) * (end - start + 2))) == NULL)
		return (NULL);
	s = start;
	while (s <= end)
		*res++ = *s++;
	*res = '\0';
	return (res - (end - start + 1));
}
