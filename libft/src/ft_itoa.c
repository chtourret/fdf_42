/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:41:43 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/13 15:01:50 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	check_neg(int nbr)
{
	int neg;

	neg = 0;
	if (nbr < 0)
		neg = 1;
	return (neg);
}

static int	count_chif(int nbr)
{
	int		chif;

	chif = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		chif++;
	}
	return (chif);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;

	neg = check_neg(n);
	str = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char *)malloc(sizeof(*str) * (neg + count_chif(n)) + 1)))
		return (NULL);
	if (neg)
	{
		str[0] = '-';
		n *= -1;
	}
	str[neg + count_chif(n)] = '\0';
	i = (neg + count_chif(n)) - 1;
	while (i >= neg)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
