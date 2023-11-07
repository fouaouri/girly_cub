/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:03:50 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/07 07:04:04 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int	*p;

	p = 0;
	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero (p, count * size);
	return (p);
}