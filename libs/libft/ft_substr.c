/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:44:29 by melhadou          #+#    #+#             */
/*   Updated: 2023/11/02 19:27:06 by fouaouri         ###   ########.fr       */
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