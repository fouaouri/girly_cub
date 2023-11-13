/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_of_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:46:36 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/13 20:48:10 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray_casting/cub3d.h"

int	count_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	square_map(struct s_mystruct *strct)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = ft_mystrlen(strct->map);
	strct->square_map = malloc(sizeof(char *) * (strct->count_map + 3));
	strct->square_map[0] = malloc(sizeof(char) * (len + 1));
	j = 0;
	while (j < len)
	{
		strct->square_map[0][j] = ' ';
		j++;
	}
	strct->square_map[0][j] = '\0';
	i = square_map2(strct, len);
	j = 0;
	strct->square_map[i] = malloc(sizeof(char) * (len + 1));
	while (j < len)
	{
		strct->square_map[i][j] = ' ';
		j++;
	}
	strct->square_map[i][j] = '\0';
	strct->square_map[i + 1] = NULL;
}

void	invalide_char(struct s_mystruct *strct)
{
	int	i;
	int	j;
	int	len;

	square_map(strct);
	j = 1;
	while (strct->square_map[j])
	{
		i = 0;
		while (strct->square_map[j][i] == ' ')
			i++;
		if (strct->square_map[j][i] && strct->square_map[j][i] != '\n')
		{
			len = ft_strlen_(strct->square_map[j]);
			len--;
			while (i < len)
			{
				check_space(strct, j, i);
				check_space2(strct, j, i);
				i++;
			}
		}
		j++;
	}
}

void	invalide_wall_(struct s_mystruct *strct)
{
	int	i;
	int	j;
	int	len;

	j = strct->count_map;
	j--;
	while (j > 0)
	{
		i = 0;
		while (strct->map[j][i] && strct->map[j][i] == ' ')
			i++;
		if (strct->map[j][i] != '\0' && strct->map[j][i] != '\n')
		{
			len = ft_strlen_(strct->map[j]);
			len -= 1;
			while (len > 0 && strct->map[j][len] == ' ')
				len--;
			if (strct->map[j][i] != '1' && strct->map[j][len] != '1')
				exit_error("should start and end with one");
		}
		j--;
	}
}

int	invalide_wall(struct s_mystruct *strct)
{
	int	i;
	int	j;
	int	l;

	l = new_ligne(strct);
	parse_first_line(strct);
	j = 0;
	i = 0;
	while (j <= l)
	{
		i = 0;
		while (strct->map[j][i] == ' ')
			i++;
		if (strct->map[j][i] == '\n')
			exit_error("a new line in map");
		j++;
	}
	check_last_ligne(strct);
	invalide_wall_(strct);
	return (0);
}
