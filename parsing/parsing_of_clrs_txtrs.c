/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_of_clrs_txtrs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:05:16 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/11 22:38:36 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray_casting/cub3d.h"

char	*color(char *north)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	start = 2;
	i = 0;
	end = ft_strlen_(north);
	end--;
	while (north[start] == ' ')
		start++;
	while (north[end] == ' ')
		end--;
	str = malloc(sizeof(char) * ((end - start) + 1));
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = north[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

int	clrs_txtrs2(struct s_mystruct *strct, int i, int j)
{
	if (strct->clrs_txtrs[j][i] == 'W'
		&& strct->clrs_txtrs[j][i + 1] == 'E'
		&& strct->clrs_txtrs[j][i + 2] == ' ')
	{
		we_check(strct, j);
		return (0);
	}
	else if (strct->clrs_txtrs[j][i] == 'E'
		&& strct->clrs_txtrs[j][i + 1] == 'A'
		&& strct->clrs_txtrs[j][i + 2] == ' ')
	{
		ea_check(strct, j);
		return (0);
	}
	else if (strct->clrs_txtrs[j][i] == 'F'
		&& strct->clrs_txtrs[j][i + 1] == ' ')
	{
		if (strct->f == 1)
			free(strct->floor);
		strct->floor = color(strct->clrs_txtrs[j]);
		strct->f++;
		return (0);
	}
	else
		return (1);
}

void	clrs_txtrs1(struct s_mystruct *strct, int i, int j)
{
	if (strct->clrs_txtrs[j][i] == 'N'
		&& strct->clrs_txtrs[j][i + 1] == 'O'
		&& strct->clrs_txtrs[j][i + 2] == ' ')
		no_check(strct, j);
	else if (strct->clrs_txtrs[j][i] == 'S'
		&& strct->clrs_txtrs[j][i + 1] == 'O'
		&& strct->clrs_txtrs[j][i + 2] == ' ')
	{
		if (strct->so == 1)
			free(strct->south);
		strct->south = ft_substr(strct->clrs_txtrs[j]);
		strct->so++;
	}
	else if (strct->clrs_txtrs[j][i] == 'C'
		&& strct->clrs_txtrs[j][i + 1] == ' ')
	{
		if (strct->c == 1)
			free(strct->ceiling);
		strct->ceiling = color(strct->clrs_txtrs[j]);
		strct->c++;
	}
	else if (clrs_txtrs2(strct, i, j) == 1)
		exit_error("invalide textures or colors");
}

void	parsing_of_clrs_txtrs(struct s_mystruct *strct)
{
	int	i;
	int	j;

	j = 0;
	strct->no = 0;
	strct->so = 0;
	strct->we = 0;
	strct->ea = 0;
	strct->f = 0;
	strct->c = 0;
	while (j < 6)
	{
		i = 0;
		while (strct->clrs_txtrs[j][i] == ' ')
			i++;
		clrs_txtrs1(strct, i, j);
		j++;
	}
	if (strct->no != 1 || strct->so != 1 || strct->we != 1
		|| strct->ea != 1 || strct->f != 1 || strct->c != 1)
		exit_error("douplicate an element");
}
