/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:32:51 by fouaouri          #+#    #+#             */
/*   Updated: 2022/11/08 23:00:35 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	result;
	int					sign;

	result = 0;
	sign = 1;
	while ((*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		if (result > LLONG_MAX && sign == -1)
			return (0);
		else if (result > LLONG_MAX && sign == 1)
			return (-1);
		str++;
	}
	return (result * sign);
}
