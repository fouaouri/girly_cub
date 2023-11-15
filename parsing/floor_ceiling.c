/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:04:19 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/15 13:55:33 by nben-ais         ###   ########.fr       */
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
		exit_error("check colors");
}

void	no_check(struct s_mystruct *strct, int i, int j)
{
	if (strct->no == 1)
		free (strct->north);
	strct->north = ft_substr(strct->clrs_txtrs[j], i);
	strct->no++;
}

void	we_check(struct s_mystruct *strct, int i, int j)
{
	if (strct->we == 1)
		free(strct->west);
	strct->west = ft_substr(strct->clrs_txtrs[j], i);
	strct->we++;
}

void	ea_check(struct s_mystruct *strct, int i, int j)
{
	if (strct->ea == 1)
		free(strct->east);
	strct->east = ft_substr(strct->clrs_txtrs[j], i);
	strct->ea++;
}
