/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:15:18 by fouaouri          #+#    #+#             */
/*   Updated: 2022/11/09 22:18:50 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long d)
{
	int	i;

	i = 0;
	if (d == 0)
		return (1);
	if (d < 0)
	{
		i++;
		d = d * (-1);
	}
	while (d > 0)
	{
		i++;
		d = d / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	len;

	len = ft_numlen (n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
		len--;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	while (n > 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len --;
	}
	return (str);
}
