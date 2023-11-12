/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_of_map3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:26:17 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/12 00:17:27 by fouaouri         ###   ########.fr       */
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

void	new_ligne_in_map2(struct s_mystruct *strct, int *j, int i)
{
	while (i < ft_strlen_(strct->map[(*j) - 1]) - 2)
	{
		while (strct->map[(*j) - 1][i] == ' ')
			i++;
		if (i < ft_strlen_(strct->map[(*j) - 1]) - 2
			&& strct->map[(*j) - 1][i] != '1')
			exit_error("map have new line");
		i++;
	}
}

void	new_ligne_in_map(struct s_mystruct *strct, int *j, int i)
{
	new_ligne_in_map2(strct, j, i);
	while (*j < strct->count_map)
	{
		i = 0;
		while (strct->map[*j][i] == ' ')
			i++;
		if (strct->map[*j][i] != '\n')
		{
			while (i < ft_strlen_(strct->map[*j]) - 2)
			{
				while (strct->map[*j][i] == ' ')
					i++;
				if (i < ft_strlen_(strct->map[*j]) - 2
					&& strct->map[*j][i] != '1')
					exit_error("map have new line");
				i++;
			}
			break ;
		}
		(*j)++;
	}
}

int	ft_strlen__(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
