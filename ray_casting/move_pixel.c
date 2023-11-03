/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:42:51 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/02 19:25:49 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall(t_builders *param, int y, int x)
{
	if (param->map[y][x] != '1')
		return (1);
	return (0);
}

void	move_player_up(t_builders *param)
{
	if (check_wall(param,
		(int)(param->coors->p_y + 0.5 * sin(param->coors->turn_direc)),
		(int)(param->coors->p_x + 0.5 * cos(param->coors->turn_direc))))
	{
		param->coors->p_x += 0.1 * cos(param->coors->turn_direc);
		param->coors->p_y += 0.1 * sin(param->coors->turn_direc);
	}
}

void	move_player_down(t_builders *param)
{
	if (check_wall(param,
		(int)(param->coors->p_y - 0.5 * sin(param->coors->turn_direc)),
		(int)(param->coors->p_x - 0.5 * cos(param->coors->turn_direc))))
	{
		param->coors->p_x -= 0.1 * cos(param->coors->turn_direc);
		param->coors->p_y -= 0.1 * sin(param->coors->turn_direc);
	}
}

int	 key_hook(t_builders *param)
{
	param->coors->turn_direc += param->view;
	if (param->up_down != MOVE)
	{
		if (param->up_down == 0)
			move_player_up(param);
		else if (param->up_down == 1)
			move_player_down(param);
	}
	get_mlx(param);
	mlx_put_image_to_window(param->mlx, param->mlx_win, param->image, 0, 0);
	return (0);
}
