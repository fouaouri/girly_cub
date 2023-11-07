/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:04:09 by fouaouri          #+#    #+#             */
/*   Updated: 2022/11/05 16:29:39 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*lorst;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	l = ft_strlen(s1) + ft_strlen(s2);
	lorst = malloc(l + 1);
	if (!lorst)
		return (NULL);
	while (s1[i])
	{
		lorst[i] = s1[i];
		i++;
	}
	while (s2[j])
		lorst[i++] = s2[j++];
	lorst[i] = '\0';
	return (lorst);
}
