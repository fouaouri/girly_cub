/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:47:05 by fouaouri          #+#    #+#             */
/*   Updated: 2022/11/05 16:29:42 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	i = 0;
	if (!src || !dstsize)
		return (ft_strlen(src));
	dstlen = ft_strlen (dst);
	j = ft_strlen (dst);
	if (dstlen >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[i] && i < (dstsize - dstlen - 1))
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (ft_strlen(src) + dstlen);
}
