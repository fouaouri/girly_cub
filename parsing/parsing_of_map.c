#include "../ray_casting/cub3d.h"

int count_map(char **map)
{
    int i;

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
	len = 0;
	while (strct->map[i] != NULL)
	{
		if (ft_strlen(strct->map[i]) > len)
			len = ft_strlen(strct->map[i]);
		else
			i++;
	}
	i = 0;
	strct->square_map = malloc(sizeof(char *) * (strct->count_map + 1));
	while (strct->map[i])
	{
		j = 0;
		if (ft_strlen(strct->map[i]) <= len)
		{
			strct->square_map[i] = malloc(sizeof(char) * (len + 2));
			while (strct->map[i][j] != '\0' && strct->map[i][j] != '\n')
			{
				strct->square_map[i][j] = strct->map[i][j];
				j++;
			}
			while (j < len)
			{
				strct->square_map[i][j] = ' ';
				j++;
			}
			strct->square_map[i][j] = '\n';
			strct->square_map[i][j + 1] = '\0';
		}
		i++;
	}
	strct->square_map[i] = NULL;
}


void	invalide_char(struct s_mystruct *strct)
{
	int	i;
	int	j;
	int	len;

	j = strct->count_map;
	j--;
	square_map(strct);
	while (j > 1)
	{
		i = 0;
		while (strct->square_map[j][i] && strct->square_map[j][i] == ' ')
			i++;
		if (strct->square_map[j][i] != '\n')
		{
			j--;
			len = ft_strlen(strct->square_map[j]);
			len -= 2;
			while (strct->square_map[j][len] == ' ')
				len--;
			while (i < len)
			{
				if (strct->square_map[j][i] == ' ' && (strct->square_map[j - 1][i] == '0'
					|| strct->square_map[j + 1][i] == '0'
					|| strct->square_map[j - 1][i] == 'N' || strct->square_map[j + 1][i] == 'N'
					|| strct->square_map[j + 1][i] == 'E' || strct->square_map[j - 1][i] == 'E'
					|| strct->square_map[j - 1][i] == 'W' || strct->square_map[j + 1][i] == 'W'
					|| strct->square_map[j + 1][i] == 'S' || strct->square_map[j - 1][i] == 'S'))
					exit (write (1, "Error\nThe map must be closed16 by walls\n", 39));
				else if (strct->square_map[j][i] == ' ' && (strct->square_map[j][i - 1] == '0' || strct->square_map[j][i + 1] == '0'
					|| strct->square_map[j][i + 1] == 'N' || strct->square_map[j][i - 1] == 'N'
					|| strct->square_map[j][i - 1] == 'W' || strct->square_map[j][i + 1] == 'W'
					|| strct->square_map[j][i - 1] == 'E' || strct->square_map[j][i + 1] == 'E'
					|| strct->square_map[j][i - 1] == 'S' || strct->square_map[j][i + 1] == 'S'))
					exit (write (1, "Error\ninvalide character\n", 25));
				else if (strct->square_map[j][i] != '0' && strct->square_map[j][i] != '1' && strct->square_map[j][i] != 'N'
					&& strct->square_map[j][i] != 'S' && strct->square_map[j][i] != 'E' && strct->square_map[j][i] != 'W'
					&& strct->square_map[j][i] != ' ')
						exit (write (1, "Error\ninvalide character\n", 25));
				else
					i++;
			}
		}
		j--;
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
		if (strct->map[j][i] != '\n')
		{
			len = ft_strlen(strct->map[j]);
			len -= 2;
			while (len > 0 && strct->map[j][len] == ' ')
				len--;
			if (strct->map[j][i] != '1' || strct->map[j][len] != '1')
				exit (write(1, "error741\n", 9));
		}
		j--;
	}
}


int	invalide_wall(struct s_mystruct *strct)
{
		int	i;
	int	j;

	i = 0;
	j = 0;
	strct->count_map = count_map(strct->map);
	while (strct->map[0][i] && strct->map[0][i] == ' ')
			i++;
	while (strct->map[0][i] != '\n')
	{
		if (strct->map[0][i] != '1')
			exit(write (1, "rerrrrrr\n", 9));
		i++;
	}
	while (j < strct->count_map)
	{
		i = 0;
		while (strct->map[j][i] == ' ')
			i++;
		if (strct->map[j][i] == '\n')
		{
			i = 0;
			while (i < ft_strlen(strct->map[j - 1]) - 2)
			{
				while (strct->map[j - 1][i] == ' ')
					i++;
				if (i < ft_strlen(strct->map[j - 1]) - 2 && strct->map[j - 1][i] != '1')
					exit (write (1, "Error120\n", 9));
				i++;
			}
			while (j < strct->count_map)
			{
				i = 0;
				while (strct->map[j][i] == ' ')
					i++;
				if (strct->map[j][i] != '\n')
				{
					while (i < ft_strlen(strct->map[j]) - 2)
					{
						while (strct->map[j][i] == ' ')
							i++;
						if (i < ft_strlen(strct->map[j]) - 2 && strct->map[j][i] != '1')
							exit (write (1, "Error1230\n", 10));
						i++;
					}
					break ;
				}
				j++;
			}
		}
		j++;
	}
	j = strct->count_map;
	
	j--;
	while (j > 0)
	{
		i = 0;
		while (strct->map[j][i] && strct->map[j][i] == ' ')
			i++;
		if (strct->map[j][i] != '\n')
		{
			while (strct->map[j][i])
			{
				if (strct->map[j][i] != '1' && strct->map[j][i] != ' ' && strct->map[j][i] != '\n')
					exit (write (1, "rrrrrrrrr\n", 10));
				i++;
			}
			break ;
		}
		j--;
	}
	invalide_wall_(strct);
	return (0);
}
