/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_of_calors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:22:44 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/07 20:47:10 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray_casting/cub3d.h"

int	ft_len(char **str)
{
	int	i;
	
	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	*ft_myatoi(char **str)
{
	int	i;
	int	j;
	int	r;
	int	*num;

	i = 0;
	r = 0;
	num = malloc(sizeof(int) * 3);
	while (str && str[i])
	{
		j = 0;
		r = 0;
		while (str[i][j])
		{
			if (str[i][j] >= '0' && str[i][j] <= '9')
			{
				r = r * 10 + str[i][j] - 48;
				j++;
			}
			else
				exit (write (1, "Error in colors1\n", 17));
		}
		num[i] = r;
		i++;
		if (r < 0 || r > 255)
			exit (write (1, "Error in colors2\n", 17));
	}
	return (num);
}

void	parsing_of_colors(struct s_mystruct *strct)
{
	char	**ceiling;
	char	**floor;
	int		*c;
	int		*f;
	int		i;

	ceiling = ft_split(strct->ceiling, ',');
	floor = ft_split(strct->floor, ',');
	if (ft_len(ceiling) != 3 || ft_len(floor) != 3)
		exit (write (1, "Error\nerror in colors\n", 22));
	i = 0;
	c = ft_myatoi(ceiling);
	f = ft_myatoi(floor);
	strct->c_value = 0;
	strct->f_value = 0;
	strct->c_value += c[0]<< 16;
	strct->c_value += c[1]<< 8;
	strct->c_value += c[2];
	strct->f_value += f[0]<< 16;
	strct->f_value += f[1]<< 8;
	strct->f_value += f[2];
	printf ("f = %d, c = %d\n", strct->f_value, strct->c_value);
}