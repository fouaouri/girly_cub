/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:04:19 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/11 01:22:17 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray_casting/cub3d.h"

void	check_comma(char *str)
{
	int	i;
	int	len;
	
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ',')
			len++;
		i++;
	}
	if (len != 2)
		exit (write (1, "Error\nerror in colors\n", 22));
}