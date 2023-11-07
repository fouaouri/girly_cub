/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:35:37 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/07 07:01:31 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *hyt, const char *ndl, size_t len)
{
	size_t	i;

	i = 0;
	if (*ndl && len == 0)
		return (0);
	if (!*ndl || len == 0)
		return ((char *)hyt);
	while (hyt[i] && len >= ft_strlen(ndl))
	{
		if (hyt[i] == ndl[0])
		{
			if (!(ft_strncmp(hyt + i, ndl, ft_strlen(ndl))))
				return ((char *)hyt + i);
		}
		i++;
		len--;
	}
	return (0);
}
