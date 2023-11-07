/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:44:38 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/07 11:45:35 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	while_flag_1(t_builders *param)
{
	while (param->pars->rectang_map[(int)param->coors->point_y][
		(int)param->coors->point_x - 1] != '1')
	{
		param->coors->c1 += 1 / cos(param->coors->g);
		param->coors->point_x -= 1;
		param->coors->point_y += tan(param->coors->g) * 1;
		if (param->coors->point_y > param->pars->count_map - 1)
			param->coors->point_y = param->pars->count_map - 1;
		if (param->coors->point_x > param->pars->max_x)
			param->coors->point_x = param->pars->max_x;
		if (param->coors->point_y < 0)
			param->coors->point_y = 0;
		if (param->coors->point_x < 0)
			param->coors->point_x = 0;
	}
}

void	while_flag_2(t_builders *param)
{
	while (param->pars->rectang_map[(int)param->coors->point_y][
		(int) param->coors->point_x] != '1')
	{
		param->coors->c1 += 1 / cos(param->coors->g);
		param->coors->point_x += 1;
		param->coors->point_y += tan(param->coors->g) * 1;
		if (param->coors->point_y > param->pars->count_map - 1)
			param->coors->point_y = param->pars->count_map - 1;
		if (param->coors->point_x > param->pars->max_x)
			param->coors->point_x = param->pars->max_x;
		if (param->coors->point_y < 0)
			param->coors->point_y = 0;
		if (param->coors->point_x < 0)
			param->coors->point_x = 0;
	}	
}

void	if_flags(t_builders *param)
{
	if (param->coors->flag == 1)
	{
		param->coors->g = param->coors->t;
		param->coors->c1 = (((int)param->coors->p_x + 1)
				- param->coors->p_x) / cos(param->coors->g);
		param->coors->point_y = (tan(param->coors->g)
				* (((int)param->coors->p_x + 1) - param->coors->p_x))
			+ param->coors->p_y;
		param->coors->point_x = (int)param->coors->p_x + 1;
	}
	else if (param->coors->flag == -1)
	{
		param->coors->g = PI - param->coors->t;
		param->coors->c1 = (param->coors->p_x - (int)param->coors->p_x)
			/ cos(param->coors->g);
		param->coors->point_y = tan(param->coors->g) * (param->coors->p_x
				- (int)param->coors->p_x) + param->coors->p_y;
		param->coors->point_x = (int)param->coors->p_x;
	}
}

void	vertical_down(t_builders *param)
{
	param->coors->flag = 0;
	if (ft_right_left(param->coors->t) == -1)
		param->coors->flag = -1;
	else if (ft_right_left(param->coors->t) == 1)
		param->coors->flag = 1;
	param->coors->g = param->coors->t;
	if_flags(param);
	if (param->coors->point_y > param->pars->count_map - 1)
		param->coors->point_y = param->pars->count_map - 1;
	if (param->coors->point_x > param->pars->max_x)
		param->coors->point_x = param->pars->max_x;
	if (param->coors->point_y < 0)
		param->coors->point_y = 0;
	if (param->coors->point_x < 0)
		param->coors->point_x = 0;
	if (param->coors->flag == -1)
		while_flag_1(param);
	else if (param->coors->flag == 1)
		while_flag_2(param);
}
