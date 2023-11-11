/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:39:37 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/11 00:48:12 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray_casting/cub3d.h"

void	rectang_map(struct s_mystruct *strct)
{
	int	i;
	int	j;

	i = 0;
	strct->rectang_map = malloc(sizeof(char *)
			* (ft_len(strct->square_map) + 1));
	strct->max_x = ft_strlen_(strct->square_map[0]) - 2;
	while (strct->square_map[i])
	{
		strct->rectang_map[i] = strct->square_map[i];
		i++;
	}
	strct->rectang_map[i] = NULL;
	i = -1;
	while (strct->rectang_map[++i])
	{
		j = 0;
		while (strct->rectang_map[i][j])
		{
			if (strct->rectang_map[i][j] == ' '
				|| strct->rectang_map[i][j] == '\n')
				strct->rectang_map[i][j] = '1';
			j++;
		}
	}
}

int	check_ligne(char *strct)
{
	int	i;

	i = 0;
	while (strct && strct[i])
	{
		while (strct[i] == ' ')
			i++;
		if (strct[i] == '\n')
			return (1);
		else
			return (0);
	}
	return (0);
}

void	parsing(char *file, int count, struct s_mystruct *strct)
{
	int		fd1;
	int		i;
	int		j;
	char	*str;

	i = 0;
	strct->count = count;
	strct->to_allocate = 0;
	fd1 = open(file, O_RDONLY);
	if (fd1 < 0)
		exit (write (2, "Error\nfailed fd1\n", 16));
	strct->file = malloc(sizeof(char *) * (strct->count + 1));
	if (strct->file == NULL)
		exit (write (2, "Error\nmalloc faild\n", 19));
	str = get_next_line(fd1);
	strct->file[i] = str;
	j = check_ligne(str);
	if (j == 0)
		strct->to_allocate++;
	count_to_allocate(fd1, i, str, strct);
	second_parsing(strct);
}

int	parce_file_name(char *name_file)
{
	int	i;

	i = 0;
	if (ft_strlen_(name_file) < 4)
		return (1);
	while (name_file[i])
		i++;
	i--;
	if (name_file[i] == 'b')
	{
		i--;
		if (name_file[i] == 'u')
		{
			i--;
			if (name_file[i] == 'c')
			{
				i--;
				if (name_file[i] == '.')
					return (0);
			}
		}
	}
	return (1);
}

void	pars_part(int ac, char **av, t_mystruct *param)
{
	int		i;
	int		fd0;
	char	*str;

	if (ac != 2)
		exit (write (2, "Error\ninvalide args number\n", 27));
	i = parce_file_name(av[1]);
	if (i == 1)
		exit (write (2, "Error\ninvalide file name\n", 25));
	fd0 = open(av[1], O_RDONLY);
	if (fd0 < 0)
		exit (write (2, "Error\nfailed fd0\n", 16));
	str = get_next_line(fd0);
	i = 0;
	while (str != NULL)
	{
		free (str);
		i++;
		str = get_next_line(fd0);
	}
	close (fd0);
	parsing(av[1], i, param);
}
