/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_of_map2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:13:48 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/11 22:41:05 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray_casting/cub3d.h"

void	square_map3(struct s_mystruct *strct, int *j, int i, int l)
{
	while (strct->map[i][*j] != '\0' && strct->map[i][*j] != '\n')
	{
		strct->square_map[l][*j] = strct->map[i][*j];
		(*j)++;
	}
}

int	square_map2(struct s_mystruct *strct, int len)
{
	int	j;
	int	i;
	int	l;

	i = -1;
	l = 1;
	while (strct->map[++i])
	{
		j = 0;
		if (ft_strlen_(strct->map[i]) <= len)
		{
			strct->square_map[l] = malloc(sizeof(char) * (len + 1));
			square_map3(strct, &j, i, l);
			while (j < len)
			{
				strct->square_map[l][j] = ' ';
				j++;
			}
			strct->square_map[l][j] = '\0';
		}
		l++;
	}
	return (l);
}

void	check_space(struct s_mystruct *strct, int j, int i)
{
	if (strct->square_map[j][i] == ' '
		&& (strct->square_map[j - 1][i] == '0'
		|| strct->square_map[j + 1][i] == '0'
		|| strct->square_map[j - 1][i] == 'N'
		|| strct->square_map[j + 1][i] == 'N'
		|| strct->square_map[j + 1][i] == 'E'
		|| strct->square_map[j - 1][i] == 'E'
		|| strct->square_map[j - 1][i] == 'W'
		|| strct->square_map[j + 1][i] == 'W'
		|| strct->square_map[j + 1][i] == 'S'
		|| strct->square_map[j - 1][i] == 'S'))
		exit_error("The map must be closed by walls");
	else if (strct->square_map[j][i] == ' '
		&& (strct->square_map[j][i - 1] == '0'
		|| strct->square_map[j][i + 1] == '0'
		|| strct->square_map[j][i + 1] == 'N'
		|| strct->square_map[j][i - 1] == 'N'
		|| strct->square_map[j][i - 1] == 'W'
		|| strct->square_map[j][i + 1] == 'W'
		|| strct->square_map[j][i - 1] == 'E'
		|| strct->square_map[j][i + 1] == 'E'
		|| strct->square_map[j][i - 1] == 'S'
		|| strct->square_map[j][i + 1] == 'S'))
		exit_error("invalide character");
}

void	check_space2(struct s_mystruct *strct, int j, int i)
{
	if (strct->square_map[j][i] != '0'
		&& strct->square_map[j][i] != '1'
		&& strct->square_map[j][i] != 'N'
		&& strct->square_map[j][i] != 'S'
		&& strct->square_map[j][i] != 'E'
		&& strct->square_map[j][i] != 'W'
		&& strct->square_map[j][i] != ' ')
		exit_error("invalide character");
}

int	ft_mystrlen(char **str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != NULL)
	{
		if (ft_strlen_(str[i]) > len)
			len = ft_strlen_(str[i]);
		else
			i++;
	}
	return (len);
}
