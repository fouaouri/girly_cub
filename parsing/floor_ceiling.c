/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:04:19 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/13 19:41:54 by nben-ais         ###   ########.fr       */
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

void	no_check(struct s_mystruct *strct, int j)
{
	if (strct->no == 1)
		free (strct->north);
	strct->north = ft_substr(strct->clrs_txtrs[j]);
	strct->no++;
}

void	we_check(struct s_mystruct *strct, int j)
{
	if (strct->we == 1)
		free(strct->west);
	strct->west = ft_substr(strct->clrs_txtrs[j]);
	strct->we++;
}

void	ea_check(struct s_mystruct *strct, int j)
{
	if (strct->ea == 1)
		free(strct->east);
	strct->east = ft_substr(strct->clrs_txtrs[j]);
	strct->ea++;
}
