/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_of_map3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:26:17 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/13 20:50:02 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray_casting/cub3d.h"

void	parse_first_line(struct s_mystruct *strct)
{
	int	i;

	i = 0;
	while (strct->map[0][i] && strct->map[0][i] == ' ')
		i++;
	while (strct->map[0][i] != '\n')
	{
		if (strct->map[0][i] != '1' && strct->map[0][i] != ' ')
			exit_error("error in the first line");
		i++;
	}
}

void	check_last_ligne(struct s_mystruct *strct)
{
	int	j;
	int	i;

	j = strct->count_map;
	j--;
	while (j > 0)
	{
		i = 0;
		while (strct->map[j][i] && strct->map[j][i] == ' ')
			i++;
		if (strct->map[j][i] != '\n')
		{
			while (strct->map[j][i])
			{
				if (strct->map[j][i] != '1'
					&& strct->map[j][i] != ' ' && strct->map[j][i] != '\n')
					exit_error("error in last ligne in the map");
				i++;
			}
			break ;
		}
		j--;
	}
}

int	ft_strlen__(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	new_ligne(struct s_mystruct *strct)
{
	int	l;
	int	i;

	strct->count_map = count_map(strct->map);
	l = strct->count_map;
	l--;
	while (l > 0)
	{
		i = 0;
		while (strct->map[l][i] == ' ')
			i++;
		if (strct->map[l][i] != '\n')
			break ;
		l--;
	}
	return (l);
}
