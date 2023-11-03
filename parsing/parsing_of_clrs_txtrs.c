#include "../ray_casting/cub3d.h"

char	*color(char *north)
{
	int	start;
	int	end;
	char	*str;
	int	i;

	start = 0;
	i = 0;
	end = ft_strlen(north);
	end--;
	while (north[start] < '0' || north[start] > '9')
		start++;
	while (north[end] == ' ')
		end--;
	str = malloc(sizeof(char) * ((end - start) + 1));
	while (start < end)
	{
		str[i] = north[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *north)
{
	int	start;
	int	end;
	char	*str;
	int	i;

	start = 0;
	i = 0;
	end = ft_strlen(north);
	end -= 2;
	while (north[start] != '.')
		start++;
	while (north[end] == ' ')
		end--;
	str = malloc(sizeof(char) * ((end - start) + 1));
	while (start < end)
	{
		str[i] = north[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
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
		while (strct->clrs_txtrs[j][i])
		{
			while (strct->clrs_txtrs[j][i] == ' ')
				i++;
			if (strct->clrs_txtrs[j][i] == 'N' && strct->clrs_txtrs[j][i + 1] == 'O' && strct->clrs_txtrs[j][i + 2] == ' ')
				{strct->north = ft_substr(strct->clrs_txtrs[j]);
				strct->no++;
				break ;}
			else if (strct->clrs_txtrs[j][i] == 'S' && strct->clrs_txtrs[j][i + 1] == 'O' && strct->clrs_txtrs[j][i + 2] == ' ')
				{strct->south = ft_substr(strct->clrs_txtrs[j]);
				strct->so++;
				break ;}
			else if (strct->clrs_txtrs[j][i] == 'W' && strct->clrs_txtrs[j][i + 1] == 'E' && strct->clrs_txtrs[j][i + 2] == ' ')
				{strct->west = ft_substr(strct->clrs_txtrs[j]);
				strct->we++;
				break ;}
			else if (strct->clrs_txtrs[j][i] == 'E' && strct->clrs_txtrs[j][i + 1] == 'A' && strct->clrs_txtrs[j][i + 2] == ' ')
				{strct->east = ft_substr(strct->clrs_txtrs[j]);
				strct->ea++;
				break ;}
			else if (strct->clrs_txtrs[j][i] == 'F' && strct->clrs_txtrs[j][i + 1] == ' ')
				{strct->floor = color(strct->clrs_txtrs[j]);
				strct->f++;
				break ;}
			else if (strct->clrs_txtrs[j][i] == 'C' && strct->clrs_txtrs[j][i + 1] == ' ')
				{strct->ceiling = color(strct->clrs_txtrs[j]);
				strct->c++;
				break ;}
			else
				exit (write(1, "Error\ninvalide textures or colors\n", 34));
			}
		j++;
	}
	if (strct->no != 1 || strct->so != 1 || strct->we != 1 || strct->ea != 1 || strct->f != 1 || strct->c != 1)
		exit (write (1, "Error\ndouplicate an element\n", 28));
}