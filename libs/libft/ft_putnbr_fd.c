/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:15:11 by fouaouri          #+#    #+#             */
/*   Updated: 2022/11/10 00:37:51 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n < 10)
	{
		ft_putchar_fd((n + '0'), fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			write (fd, "2147483648", 10);
		}
		else
		{
			n = -1 * n;
			ft_putnbr_fd(n, fd);
		}
	}
	else if (n >= 10)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putnbr_fd (n % 10, fd);
	}
}
