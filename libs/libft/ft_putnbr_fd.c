/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:45:37 by melhadou          #+#    #+#             */
/*   Updated: 2023/09/15 19:26:44 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int nbr, int fd)
{
	int		val;
	char	c;

	val = 0;
	if (nbr == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (nbr < 0)
	{
		val += write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		val += ft_putnbr_fd(nbr / 10, fd);
	c = nbr % 10 + '0';
	val += write(fd, &c, 1);
	return (val);
}
