/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:26:07 by fouaouri          #+#    #+#             */
/*   Updated: 2022/11/05 16:30:03 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start_s(char const *s1, char const *set)
{
	int	start;
	int	j;

	start = 0;
	j = 0;
	while (s1[start] && set[j])
	{
		if (s1[start] == set[j])
		{
			start++;
			j = 0;
		}
		else
			j++;
	}
	return (start);
}

static int	ft_end_s(char const *s1, char const *set)
{
	int		end;
	int		j;

	end = ft_strlen(s1) - 1;
	j = 0;
	while (end >= 0 && set[j])
	{
		if (s1[end] == set[j])
		{
			end--;
			j = 0;
		}
		else
			j++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	int		size;
	char	*copy;

	if (!s1)
		return (NULL);
	start = ft_start_s(s1, set);
	end = ft_end_s(s1, set);
	copy = 0;
	i = 0;
	if (start < end)
		size = end - start + 1;
	else
		size = 0;
	copy = malloc(size + 1);
	if (!copy)
		return (NULL);
	while (start <= end)
		copy[i++] = s1[start++];
	copy[i] = '\0';
	return (copy);
}
