/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:16:52 by fouaouri          #+#    #+#             */
/*   Updated: 2022/11/10 00:37:21 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;

	i = 0;
	str = ((const char *)s);
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
