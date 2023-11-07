/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:51:48 by fouaouri          #+#    #+#             */
/*   Updated: 2022/11/05 16:30:53 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (len == 0)
		return (dst);
	if (dst > src)
	{
		i = len - 1 ;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
		return ((void *) d);
	}
	else
		return (ft_memcpy(dst, src, len));
}
