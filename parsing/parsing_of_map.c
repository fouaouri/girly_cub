#include "../ray_casting/cub3d.h"

int count_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

void	invalide_char(struct s_mystruct *strct)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	while (j < strct->count_map - 1)
	{
		i = 0;
		len = ft_strlen(strct->map[j]);
		len -= 2;
		while (strct->map[j][len] == ' ')
			len--;
		while (strct->map[j][i] == ' ')
			i++;
		while (i < len)
		{
			if (strct->map[j][i] == ' ' && (strct->map[j - 1][i] == '0' || strct->map[j + 1][i] == '0'
				|| strct->map[j - 1][i] == 'N' || strct->map[j + 1][i] == 'N'
				|| strct->map[j + 1][i] == 'E' || strct->map[j - 1][i] == 'E'
				|| strct->map[j - 1][i] == 'W' || strct->map[j + 1][i] == 'W'
				|| strct->map[j + 1][i] == 'S' || strct->map[j - 1][i] == 'S'))
				exit (write (1, "Error\nThe map must be closed1 by walls\n", 38));
			else if (strct->map[j][i] == ' ' && (strct->map[j][i - 1] == '0' || strct->map[j][i + 1] == '0'
				|| strct->map[j][i + 1] == 'N' || strct->map[j][i - 1] == 'N'
				|| strct->map[j][i - 1] == 'W' || strct->map[j][i + 1] == 'W'
				|| strct->map[j][i - 1] == 'E'  || strct->map[j][i + 1] == 'E'
				|| strct->map[j][i - 1] == 'S' || strct->map[j][i + 1] == 'S'))
				exit (write (1, "Error\ninvalide character\n", 25));
			else if (strct->map[j][i] != '0' && strct->map[j][i] != '1' && strct->map[j][i] != 'N'
				&& strct->map[j][i] != 'S' && strct->map[j][i] != 'E' && strct->map[j][i] != 'W'
				&& strct->map[j][i] != ' ')
					exit (write (1, "Error\ninvalide character\n", 25));
			else
				i++;
		}
		j++;
	}
}


int	invalide_wall_(struct s_mystruct *strct)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < strct->count_map)
	{
		i = 0;
		while (strct->map[j][i])
		{
			while (strct->map[j][i] == ' ')
				i++;
			if (strct->map[j][i] != '1')
				exit (write (1, "Error\nThe map must be closed1 by walls\n", 38));
			break ;
		}
		j++;
	}
	j = 1;
	while (j < strct->count_map - 2)
	{
		i = ft_strlen(strct->map[j]);
		i -= 2;
		while (i > 0)
		{
			while (strct->map[j][i] == ' ')
				i--;
			if (strct->map[j][i] != '1')
				exit (write (1, "Error\nThe map must be closed2 by walls\n", 38));
			break ;
			i--;
		}
		j++;
	}
	return (0);
}


int	invalide_wall(struct s_mystruct *strct)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(strct->map[0]);
	len -= 2;
	while (strct->map[0][i] == ' ')
		i++;
	while (strct->map[0][len] == ' ')
		len--;
	while (i < len)
	{
		if (strct->map[0][i] != '1' && strct->map[0][i] != ' ')
			exit (write (1, "Error\nThe map must be closed3 by walls\n", 39));
		i++;
	}
	i = 0;
    strct->count_map = count_map(strct->map);
	len = ft_strlen(strct->map[strct->count_map - 1]);
	len -= 2;
	while (strct->map[strct->count_map - 1][i] == ' ')
		i++;
	while (strct->map[strct->count_map - 1][len] == ' ')
		len--;
	while (i < len)
	{
		if (strct->map[strct->count_map - 1][i] != '1' && strct->map[strct->count_map - 1][i] != ' ')
			exit (write (1, "Error\nThe map must be closed4 by walls\n", 38));
		i++;
	}
	invalide_wall_(strct);
	return (0);
}
