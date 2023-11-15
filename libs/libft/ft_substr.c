/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:53:29 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/15 13:58:00 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *north, int l)
{
	int		start;
	int		end;
	char	*str;
	int		i;
	int		len;

	start = l + 3;
	i = 0;
	end = ft_strlen_(north);
	end -= 2;
	while (north[start] == ' ')
		start++;
	while (north[end] == ' ')
		end--;
	len = end - start;
	str = malloc(sizeof(char) * (len + 1));
	while (start <= end)
	{
		str[i] = north[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
