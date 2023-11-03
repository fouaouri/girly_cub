/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_value_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:24:40 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/03 11:43:58 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_mlx(t_builders *param)
{
		int		endian;
		int		bits_per_pixel;
	if (param->mlx_win)
	{
		return_after_2_pi(*param);
		if(param->image)
			mlx_destroy_image(param->mlx,param->image);
		param->image = mlx_new_image(param->mlx, 1200, 800);
		param->data = (unsigned int *)mlx_get_data_addr(param->image, &bits_per_pixel, &param->coors->size_line, &endian);

		draw_mini_map(param);
		pose_player(param);
	}
}

int	hooking(int key, t_builders *param)
{
	if (key == ESC)
	{
		mlx_destroy_window(param->mlx, param->mlx_win);
		printf("you end the game");
		// free(param);
		exit(0);
	}
	if (key == UP)
		param->up_down = 0;
	if (key == DOWN)
		param->up_down = 1;
	if (key == RIGHT)
		param->view = 0.01;
	if (key == LEFT)
		param->view = -0.01;
	return (0);
}

int	realising(int key, t_builders *param)
{
	if (key == UP || key == DOWN)
		param->up_down = MOVE;
	if (key == LEFT || key == RIGHT)
		param->view = TURN_DIREC;
	return (1);
}

void data_value(t_builders *param, int y, int x, int color)
{
	if (y  >= 800 || x >= 1200)
		return ;
	else if(y < 0 || x < 0)
		return ;
	else
		param->data[(y * (param->coors->size_line / 4)) + x] = color;
}