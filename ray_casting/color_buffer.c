/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:55:55 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/07 09:01:36 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	n_color_buffer(t_builders *param, double wall_len, double i, double j)
{
	param->coors->color = (((int)(j * 250 / wall_len) % 250)
			* (param->coors->size_line_north / 4))
		+ (param->coors->point_x1 - (int)param->coors->point_x1) * 250;
	put_img(param,
		param->data_north[param->coors->color], param->coors->a, i + j);
}

void	s_color_buffer(t_builders *param, double wall_len, double i, double j)
{
	param->coors->color = (((int)(j * 250 / wall_len) % 250)
			* (param->coors->size_line_s / 4))
		+ (param->coors->point_x1 - (int)param->coors->point_x1) * 250;
	put_img(param,
		param->data_s[param->coors->color], param->coors->a, i + j);
}

void	w_color_buffer(t_builders *param, double wall_len, double i, double j)
{
	param->coors->color = (((int)(j * 250 / wall_len) % 250)
			* (param->coors->size_line_w / 4))
		+ (param->coors->point_y - (int)param->coors->point_y) * 250;
	put_img(param,
		param->data_w[param->coors->color], param->coors->a, i + j);
}

void	e_color_buffer(t_builders *param, double wall_len, double i, double j)
{
	param->coors->color = (((int)(j * 250 / wall_len) % 250)
			* (param->coors->size_line_e / 4))
		+ (param->coors->point_y - (int)param->coors->point_y) * 250;
	put_img(param,
		param->data_e[param->coors->color], param->coors->a, i + j);
}

void	color_buffer(t_builders *param, double wall_len, double i, double j)
{
	if (param->coors->direc == 'n')
		n_color_buffer(param, wall_len, i, j);
	else if (param->coors->direc == 's')
		s_color_buffer(param, wall_len, i, j);
	else if (param->coors->direc == 'w')
		w_color_buffer(param, wall_len, i, j);
	else if (param->coors->direc == 'e')
		e_color_buffer(param, wall_len, i, j);
}
