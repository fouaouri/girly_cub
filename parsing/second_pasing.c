
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_pasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:29:13 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/05 17:21:11 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray_casting/cub3d.h"

void    num_of_player(struct s_mystruct *strct)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (j < strct->count_map)
	{
		i = 0;
		while (strct->map[j][i])
		{
			if (strct->map[j][i] == 'W' || strct->map[j][i] == 'E'
				|| strct->map[j][i] == 'N' || strct->map[j][i] == 'S')
				p++;
			i++;
		}
		j++;
	}
	if (p != 1)
		exit (write (2, "Error\nthe player should be one\n", 31));
}

void	store_map(struct s_mystruct *strct, int i)
{
	int	j;
	int	l;

	j = 0;
	l = strct->to_allocate - i;
	if (strct->content[i] == NULL)
		exit (write (1, "Error\nthere is no map\n", 22));
	strct->map = malloc(sizeof(char *) * (l + 1));
	while (j < l)
	{
		strct->map[j] = strct->content[i];
		i++;
		j++;
	}
	strct->map[j] = NULL;	
	parsing_of_clrs_txtrs(strct);
	parsing_of_colors(strct);
	invalide_wall(strct);
	invalide_char(strct);
	num_of_player(strct);

}

void	store_clrs_txtrs(struct s_mystruct *strct)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	strct->clrs_txtrs = malloc(sizeof(char *) * 7);
	while (i < 6)
	{
		strct->clrs_txtrs[i] = strct->content[j];
		i++;
		j++;
	}
	strct->clrs_txtrs[i] = NULL;
	store_map(strct, i);
}

void	second_parsing(struct s_mystruct *strct)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	l = 0;
	strct->content = malloc(sizeof(char *) * (strct->to_allocate + 1));
	while (j < strct->count)
	{
		i = 0;
		while (strct->file[j][i])
		{
			while (strct->file[j][i] != '\0' && strct->file[j][i] == ' ')
				i++;
			if (l < 7 && strct->file[j][i] == '\n')
				break ;
			else
			{
				strct->content[l] = strct->file[j];
				l++;
				break ;
			}
			i++;
		}
		j++;
	}
	strct->content[l] = NULL;
	store_clrs_txtrs(strct);
}
