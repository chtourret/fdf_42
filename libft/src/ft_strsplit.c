/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:59:40 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/13 15:07:28 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_count(char *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_create_wrd(char *s, int *i, char c)
{
	int		index;
	char	*tmp;

	if (!s)
		return (NULL);
	if ((tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	index = 0;
	while (s[*i] != c && s[*i])
	{
		tmp[index] = s[*i];
		index++;
		*i = *i + 1;
	}
	tmp[index] = '\0';
	return (tmp);
}

char		**ft_strsplit(char const *s, char c)
{
	int		word;
	int		i;
	int		j;
	char	**str;

	if (!s)
		return (NULL);
	word = ft_count((char *)s, c);
	if ((str = (char **)malloc(sizeof(*str) * word + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i] == c && s[i])
		i++;
	j = 0;
	while (j < word)
	{
		if (s[i] == c)
			while (s[i] == c && s[i])
				i++;
		str[j] = ft_create_wrd((char *)s, &i, c);
		j++;
	}
	str[j] = NULL;
	return (str);
}
