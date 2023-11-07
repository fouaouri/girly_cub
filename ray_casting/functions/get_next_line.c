/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:50:57 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/07 07:21:17 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char	*read_file(int fd, char *counter)
{
	char	*buffer;
	int		readed;

	buffer = malloc(((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readed = 1;
	while (readed)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == 0)
			break ;
		if (readed == -1)
			return (free(buffer), free(counter), NULL);
		buffer[readed] = '\0';
		counter = ft_strjoin(counter, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (counter);
}

char	*put_on_the_line(char *counter)
{
	char	*line;
	int		i;

	i = 0;
	if (*counter == 0)
		return (NULL);
	while (counter && counter[i] && counter[i] != '\n')
		i++;
	if (counter[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (counter[i] && counter[i] != '\n')
	{
		line[i] = counter[i];
		i++;
	}
	if (counter[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_update(char *counter)
{
	char	*update;
	int		i;
	int		j;

	i = 0;
	while (counter[i] && counter[i] != '\n')
		i++;
	if (counter[i] == 0)
		return (free(counter), NULL);
	update = (char *)malloc(sizeof(char) * (ft_strlen(counter) - i + 1));
	if (!update)
		return (free(counter), NULL);
	i++;
	j = 0;
	while (counter[i])
		update[j++] = counter[i++];
	update[j] = '\0';
	return (free(counter), update);
}

char	*get_next_line(int fd)
{
	static char	*counter;
	char		*line;

	if (counter == NULL)
		counter = ft_calloc(1, 1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	counter = read_file(fd, counter);
	if (!counter)
		return (NULL);
	line = put_on_the_line(counter);
	counter = get_update(counter);
	return (line);
}
