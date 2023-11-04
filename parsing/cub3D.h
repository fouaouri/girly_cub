/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:16:36 by nben-ais          #+#    #+#             */
/*   Updated: 2023/11/04 19:11:42 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"

struct s_mystruct{
	char	**map;
	char	**square_map;
	char	**clrs_txtrs;
	char	**file;
	char	**content;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		count;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	int		to_allocate;
	int		len;
	int		count_map;
};

int		ft_strlen(char *str);
void	short_ligne(char **str, int len);
char	*ft_strjoin_(char *s1, char *s2);
int		invalide_wall(struct s_mystruct *strct);
void	invalide_char(struct s_mystruct *strct);
void    num_of_player(struct s_mystruct *strct);
void	parsing_of_clrs_txtrs(struct s_mystruct *strct);
void    second_parsing(struct s_mystruct *strct);

# endif