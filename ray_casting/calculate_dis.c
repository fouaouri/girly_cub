/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_dis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:07:52 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/10 20:44:45 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(void)
{
	printf("You end the program!\n");
	exit (0);
	return (0);
}

void	init_draw_rays(t_builders *param)
{
	param->coors->f = 0;
	param->coors->g = 0;
	param->coors->c = 0;
	param->coors->r = 0;
	param->coors->c1 = 0;
	param->coors->point_x = 0;
	param->coors->point_x1 = 0;
	param->coors->point_y = 0;
	if (ft_up_down(param->coors->t) == -1)
		hori_up(param);
	else if (ft_up_down(param->coors->t) == 1)
		hori_down(param);
	param->coors->point_x1 = param->coors->point_x;
	if (ft_up_down(param->coors->t) == 1)
		vertical_down(param);
	else if (ft_up_down(param->coors->t) == -1)
		vertical_up(param);
}

void	draw_rays(t_builders *param)
{
	init_draw_rays(param);
	if (param->coors->c <= param->coors->c1)
	{
		if (ft_up_down(param->coors->t) == -1)
			param->coors->direc = 'n';
		else
			param->coors->direc = 's';
		param->coors->r = param->coors->c;
	}
	else if (param->coors->c1 <= param->coors->c)
	{
		if (ft_right_left(param->coors->t) == -1)
			param->coors->direc = 'w';
		else
			param->coors->direc = 'e';
		param->coors->r = param->coors->c1;
	}
}
