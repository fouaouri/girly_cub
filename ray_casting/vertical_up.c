/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:45:59 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/07 11:46:25 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	while_flag_3(t_builders *param)
{
	while (param->pars->rectang_map[(int)param->coors->point_y][
		(int) param->coors->point_x - 1] != '1')
	{
		param->coors->c1 += 1 / cos(param->coors->g);
		param->coors->point_x -= 1;
		param->coors->point_y -= tan(param->coors->g) * 1;
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

void	while_flag_4(t_builders *param)
{
	while (param->pars->rectang_map[(int)param->coors->point_y][
		(int) param->coors->point_x + 1] != '1')
	{
		param->coors->c1 += 1 / cos(param->coors->g);
		param->coors->point_x += 1;
		param->coors->point_y -= tan(param->coors->g) * 1;
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

void	if_flags1(t_builders *param)
{
	if (param->coors->flag == -1)
	{
		param->coors->g = param->coors->t - PI;
		param->coors->c1 = (param->coors->p_x - (int)param->coors->p_x)
			/ cos(param->coors->g);
		param->coors->point_y = param->coors->p_y - (tan(param->coors->g)
				* (param->coors->p_x - (int)param->coors->p_x));
	}
	else if (param->coors->flag == 1)
	{
		param->coors->g = (2 * PI) - param->coors->t;
		param->coors->c1 = ((int)param->coors->p_x + 1 - param->coors->p_x)
			/ cos(param->coors->g);
		param->coors->point_y = param->coors->p_y - (tan(param->coors->g)
				* ((int)param->coors->p_x + 1 - param->coors->p_x));
	}
}

void	vertical_up(t_builders *param)
{
	param->coors->flag = 0;
	if (ft_right_left(param->coors->t) == -1)
		param->coors->flag = -1;
	else if (ft_right_left(param->coors->t) == 1)
		param->coors->flag = 1;
	if_flags1(param);
	param->coors->point_x = (int)param->coors->p_x;
	if (param->coors->point_y > param->pars->count_map - 1)
		param->coors->point_y = param->pars->count_map - 1;
	if (param->coors->point_x > param->pars->max_x)
		param->coors->point_x = param->pars->max_x;
	if (param->coors->point_y < 0)
		param->coors->point_y = 0;
	if (param->coors->point_x < 0)
		param->coors->point_x = 0;
	if (param->coors->flag == -1)
		while_flag_3(param);
	else if (param->coors->flag == 1)
		while_flag_4(param);
}
