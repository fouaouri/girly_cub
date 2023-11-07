/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:42:34 by fouaouri          #+#    #+#             */
/*   Updated: 2022/11/13 01:55:26 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*p;

	i = 0;
	if (!s)
		return (0);
	p = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	return (p);
}
