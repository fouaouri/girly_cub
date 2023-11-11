/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_of_calors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:22:44 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/11 22:37:42 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray_casting/cub3d.h"

void	count_to_allocate(int fd1, int i, char *str, struct s_mystruct *strct)
{
	int	l;
	int	j;

	j = 0;
	l = 0;
	while (str != NULL)
	{
		str = get_next_line(fd1);
		strct->file[++i] = str;
		if (l < 6)
		{
			j = check_ligne(str);
			if (j == 0)
				strct->to_allocate++;
		}
		if (l > 6)
			strct->to_allocate++;
		l++;
	}
}

int	ft_len(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_myatoi2(char *str, int *r)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] >= '0' && str[j] <= '9')
			*r = *r * 10 + str[j] - 48;
		else
			exit_error("check colors");
		j++;
	}
}

int	*ft_myatoi(char **str)
{
	int	i;
	int	r;
	int	*num;

	num = malloc(sizeof(int) * 3);
	i = 0;
	while (str && str[i])
	{
		r = 0;
		if (ft_strlen_(str[i]) > 3)
			exit_error("check colors");
		ft_myatoi2(str[i], &r);
		num[i] = r;
		if (r < 0 || r > 255)
			exit_error("check colors");
		i++;
	}
	ft_free (str);
	return (num);
}

void	parsing_of_colors(struct s_mystruct *strct)
{
	char	**ceiling;
	char	**floor;
	int		*c;
	int		*f;

	check_comma(strct->ceiling);
	check_comma(strct->floor);
	ceiling = ft_split(strct->ceiling, ',');
	floor = ft_split(strct->floor, ',');
	if (ft_len(ceiling) != 3 || ft_len(floor) != 3)
		exit_error("check colors");
	c = ft_myatoi(ceiling);
	f = ft_myatoi(floor);
	strct->c_value = 0;
	strct->f_value = 0;
	strct->c_value += c[0] << 16;
	strct->c_value += c[1] << 8;
	strct->c_value += c[2];
	strct->f_value += f[0] << 16;
	strct->f_value += f[1] << 8;
	strct->f_value += f[2];
	free (c);
	free (f);
}
