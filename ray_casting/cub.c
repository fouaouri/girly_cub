/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 03:13:06 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/07 21:06:58 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_pose_player(t_builders *param)
{
	param->coors->w = 0;
	param->coors->t = param->coors->turn_direc - (PI / 6);
	param->coors->a = 0;
	param->coors->b = 0;
}

void	pose_player(t_builders *param)
{
	init_pose_player(param);
	while (param->coors->b <= 1.0471975512)
	{
		return_after_2_pi1(param);
		draw_rays(param);
		param->coors->j = 0;
		param->coors->wall_len = 800 / (param->coors->r
				* cos(param->coors->turn_direc - param->coors->t));
		param->coors->wall_len2 = param->coors->wall_len;
		param->coors->i = 400 - param->coors->wall_len / 2;
		if (param->coors->wall_len > 800)
		{
			param->coors->j = param->coors->wall_len2 / 2 - 550;
			if (param->coors->j < 0)
				param->coors->j = 0;
			param->coors->wall_len2 = param->coors->wall_len2 / 2 + 400;
		}
		while (param->coors->j <= param->coors->wall_len2)
			color_buffer(param, param->coors->wall_len,
				param->coors->i, param->coors->j++);
		param->coors->t += 0.00087266462;
		param->coors->a += 1;
		param->coors->b += 0.00087266462;
	}
}

void	get_floor_ceiling(t_builders *param)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT / 2)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			data_value(param, i, j, param->pars->c_value);
			j++;
		}
		i++;
	}
	i = WIN_HEIGHT / 2;
	while (i <= WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			data_value(param, i, j, param->pars->f_value);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_builders		*param;
	t_coordinates	coor;
	t_mystruct		pars;

	param = malloc(sizeof(t_builders));
	param->coors = &coor;
	param->pars = &pars;
	init_main(param);
	pars_part(ac, av, &pars);
	rectang_map(&pars);
	init_player(param);
	init_mlx(param);
	loop_mlx(param);
}
