/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:42:29 by fouaouri          #+#    #+#             */
/*   Updated: 2022/11/05 16:30:00 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;

	len = ft_strlen(s);
	while (len)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
		len--;
	}
	if (s[0] == (char)c)
		return ((char *)(s + len));
	len = ft_strlen(s);
	if ((char )c == '\0')
		return ((char *)(s + len));
	return (0);
}
