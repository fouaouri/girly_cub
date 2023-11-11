/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_pasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:29:13 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/11 22:45:12 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray_casting/cub3d.h"

void	num_of_player(struct s_mystruct *strct)
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
		exit_error("the player should be one");
}

void	helper(struct s_mystruct *strct)
{
	parsing_of_clrs_txtrs(strct);
	parsing_of_colors(strct);
	invalide_wall(strct);
	invalide_char(strct);
	num_of_player(strct);
}

void	store_map(struct s_mystruct *strct, int i)
{
	int	j;
	int	l;
	int	flag;

	j = 0;
	flag = 0;
	l = strct->to_allocate - i;
	if (strct->content[i] == NULL)
		exit_error("there is no map");
	strct->map = malloc(sizeof(char *) * (l + 1));
	while (j < l)
	{
		if (!is_space(strct->content[i]) && flag == 1)
			exit_error("there is a new line in the map");
		if (is_space(strct->content[i]))
			flag = 1;
		strct->map[j] = strct->content[i];
		i++;
		j++;
	}
	strct->map[j] = NULL;
	helper(strct);
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

	j = -1;
	strct->l = 0;
	strct->content = malloc(sizeof(char *) * (strct->to_allocate + 1));
	while (++j < strct->count)
	{
		i = -1;
		while (strct->file[j][++i])
		{
			while (strct->file[j][i] == ' ')
				i++;
			if (strct->l < 7 && strct->file[j][i] == '\n')
				break ;
			else
			{
				strct->content[strct->l] = strct->file[j];
				strct->l++;
				break ;
			}
		}
	}
	strct->content[strct->l] = NULL;
	store_clrs_txtrs(strct);
}
