/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 03:13:06 by fouaouri          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/10 19:20:20 by nben-ais         ###   ########.fr       */
=======
/*   Updated: 2023/11/10 20:14:19 by fouaouri         ###   ########.fr       */
>>>>>>> 9b08373431e0867e95a2827b7b09e13bb9d94cd9
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
	while (param->coors->b <= (PI / 3))
	{
		return_after_2_pi1(param);
		draw_rays(param);
		param->coors->j = 0;
		param->coors->wall_len = WIN_HEIGHT / (param->coors->r
				* cos(param->coors->turn_direc - param->coors->t));
		param->coors->wall_len2 = param->coors->wall_len;
		param->coors->i = (WIN_HEIGHT / 2) - param->coors->wall_len / 2;
		if (param->coors->wall_len > 800)
		{
			param->coors->j = param->coors->wall_len2 / 2 - 400;
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

void	player_direction(t_builders *param)
{
	int	i;
	int	j;

	i = 0;
	while (param->pars->rectang_map[i])
	{
		j = 0;
		while (param->pars->rectang_map[i][j])
		{
			if (param->pars->rectang_map[i][j] == 'N')
				param->coors->turn_direc = (3 * PI) / 2;
			else if (param->pars->rectang_map[i][j] == 'S')
				param->coors->turn_direc = PI / 2;
			else if (param->pars->rectang_map[i][j] == 'E')
				param->coors->turn_direc = 0;
			else if (param->pars->rectang_map[i][j] == 'W')
				param->coors->turn_direc = PI;
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
	player_direction(param);
	init_player(param);
	init_mlx(param);
	loop_mlx(param);
}
