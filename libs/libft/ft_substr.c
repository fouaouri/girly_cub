/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:53:29 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/07 07:02:29 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *north)
{
	int	start;
	int	end;
	char	*str;
	int	i;

	start = 0;
	i = 0;
	end = ft_strlen(north);
	end -= 2;
	while (north[start] != '.')
		start++;
	while (north[end] == ' ')
		end--;
	str = malloc(sizeof(char) * ((end - start) + 1));
	while (start < end)
	{
		str[i] = north[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
