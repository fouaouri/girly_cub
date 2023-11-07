/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_value_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:24:40 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/07 11:50:51 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall(t_builders *param, int y, int x)
{
	if (param->pars->rectang_map[y][x] != '1')
		return (1);
	return (0);
}

void	get_mlx(t_builders *param)
{
	int	endian;
	int	bits_per_pixel;

	if (param->mlx_win)
	{
		return_after_2_pi(*param);
		if (param->image)
			mlx_destroy_image(param->mlx, param->image);
		param->image = mlx_new_image(param->mlx, 1200, 800);
		param->data = (unsigned int *)mlx_get_data_addr(param->image,
				&bits_per_pixel, &param->coors->size_line, &endian);
		// get_floor_ceiling(param);
		pose_player(param);
	}
}

int	hooking(int key, t_builders *param)
{
	if (key == ESC)
	{
		mlx_destroy_window(param->mlx, param->mlx_win);
		printf("you end the game");
		free(param);
		exit(0);
	}
	if (key == UP)
		param->up_down = 0;
	if (key == DOWN)
		param->up_down = 1;
	if (key == A_LEFT)
		param->up_down = 2;
	if (key == D_RIGHT)
		param->up_down = 3;
	if (key == RIGHT)
		param->view = 0.02;
	if (key == LEFT)
		param->view = -0.02;
	return (0);
}

int	realising(int key, t_builders *param)
{
	if (key == UP || key == DOWN || key == A_LEFT || key == D_RIGHT)
		param->up_down = MOVE;
	if (key == LEFT || key == RIGHT)
		param->view = TURN_DIREC;
	return (1);
}

void	data_value(t_builders *param, int y, int x, int color)
{
	if (y >= 800 || x >= 1200)
		return ;
	else if (y < 0 || x < 0)
		return ;
	else
		param->data[(y * (param->coors->size_line / 4)) + x] = color;
}
