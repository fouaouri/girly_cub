/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:03:23 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/15 19:33:55 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray_casting/cub3d.h"

void	check_space_(char **map)
{
	int	i;
	int	len;
	int	j;
	int	l;

	i = 1;
	l = count_map(map) - 1;
	while (i < l)
	{
		j = 1;
		len = ft_strlen_(map[i]);
		while (j < len)
		{
			if (map[i][j] == ' ' && (map[i][j + 1] == '0'
				|| map[i][j - 1] == '0'
				|| map[i + 1][j] == '0'
				|| map[i - 1][j] == '0'))
				exit_error ("map should be close by walls");
			j++;
		}
		i++;
	}
}
