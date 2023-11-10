/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hori_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:42:17 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/10 17:05:09 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hori_up(t_builders *param)
{
	if (ft_right_left(param->coors->t) == 1)
	{
		param->coors->f = param->coors->t - ((3 * PI) / 2);
		param->coors->point_x = tan(param->coors->f)
			* (param->coors->p_y - (int)param->coors->p_y) + param->coors->p_x;
	}
	else if (ft_right_left(param->coors->t) == -1)
	{
		param->coors->f = ((3 * PI) / 2) - param->coors->t;
		param->coors->point_x = param->coors->p_x - (tan(param->coors->f)
				* (param->coors->p_y - (int)param->coors->p_y));
	}
	param->coors->c = (param->coors->p_y - (int)param->coors->p_y)
		/ cos(param->coors->f);
	param->coors->point_y = (int)param->coors->p_y;
	if (param->coors->point_y > param->pars->count_map)
		param->coors->point_y = param->pars->count_map;
	if (param->coors->point_x > param->pars->max_x)
		param->coors->point_x = param->pars->max_x;
	if (param->coors->point_y < 0)
		param->coors->point_y = 0;
	if (param->coors->point_x < 0)
		param->coors->point_x = 0;
}

void	hori_up(t_builders *param)
{
	init_hori_up(param);
	while (param->pars->rectang_map[(int)param->coors->point_y
			- 1][(int)param->coors->point_x] != '1')
	{
		param->coors->c += 1 / cos(param->coors->f);
		if (ft_right_left(param->coors->t) == -1)
			param->coors->point_x -= tan(param->coors->f) * 1;
		else if (ft_right_left(param->coors->t) == +1)
			param->coors->point_x += tan(param->coors->f) * 1;
		param->coors->point_y -= 1;
		if (param->coors->point_y > param->pars->count_map)
			param->coors->point_y = param->pars->count_map;
		if (param->coors->point_x > param->pars->max_x)
			param->coors->point_x = param->pars->max_x;
		if (param->coors->point_y < 0)
			param->coors->point_y = 0;
		if (param->coors->point_x < 0)
			param->coors->point_x = 0;
	}
}

void	init_hori_down(t_builders *param)
{
	if (ft_right_left(param->coors->t) == 1)
	{
		param->coors->f = (PI / 2) - param->coors->t;
		param->coors->point_x = tan(param->coors->f)
			* (((int)param->coors->p_y + 1)
				- param->coors->p_y) + param->coors->p_x;
	}
	else if (ft_right_left(param->coors->t) == -1)
	{
		param->coors->f = param->coors->t - (PI / 2);
		param->coors->point_x = param->coors->p_x - (tan(param->coors->f)
				* (((int)param->coors->p_y + 1) - param->coors->p_y));
	}
	param->coors->c = (((int)param->coors->p_y + 1) - param->coors->p_y)
		/ cos(param->coors->f);
	param->coors->point_y = (int)param->coors->p_y;
	if (param->coors->point_y > param->pars->count_map)
		param->coors->point_y = param->pars->count_map;
	if (param->coors->point_x > param->pars->max_x)
		param->coors->point_x = param->pars->max_x;
	if (param->coors->point_y < 0)
		param->coors->point_y = 0;
	if (param->coors->point_x < 0)
		param->coors->point_x = 0;
}

void	hori_down(t_builders *param)
{
	init_hori_down(param);
	while (param->pars->rectang_map[(int)param->coors->point_y
			+ 1][(int)param->coors->point_x] != '1')
	{
		param->coors->c += 1 / cos(param->coors->f);
		if (ft_right_left(param->coors->t) == -1)
			param->coors->point_x -= tan(param->coors->f) * 1;
		else if (ft_right_left(param->coors->t) == +1)
			param->coors->point_x += tan(param->coors->f) * 1;
		param->coors->point_y += 1;
		if (param->coors->point_y > param->pars->count_map)
			param->coors->point_y = param->pars->count_map;
		if (param->coors->point_x > param->pars->max_x)
			param->coors->point_x = param->pars->max_x;
		if (param->coors->point_y < 0)
			param->coors->point_y = 0;
		if (param->coors->point_x < 0)
			param->coors->point_x = 0;
	}
}
