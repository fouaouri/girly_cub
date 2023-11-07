/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:23:37 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/07 11:50:38 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_img(t_builders *param, int wall_len, int x, int y)
{
	int	pose;

	pose = (y * param->coors->size_line / 4) + x;
	if (pose >= (1200 * 800))
		return ;
	else if (pose < 0)
		return ;
	param->data[pose] = wall_len;
}

void	init_main(t_builders *param)
{
	param->moves = 0;
	param->coors->height = 0;
	param->coors->turn_direc = 0;
	param->coors->direction = 0;
	param->image = NULL;
	param->image_north = NULL;
	param->up_down = -1;
	param->view = 0;
}

void	init_player(t_builders *param)
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
			{
				param->coors->p_x = j + 0.5;
				param->coors->p_y = i + 0.5;
			}
			j++;
		}
		i++;
	}
}

void	init_mlx(t_builders *param)
{
	int	h;
	int	w;

	param->mlx = mlx_init();
	param->mlx_win = mlx_new_window(param->mlx, WIN_WIDTH, WIN_HEIGHT, "CHAMA");
	param->image_north = mlx_xpm_file_to_image(param->mlx,
			"ray_casting/textures/np.xpm", &h, &w);
	param->image_s = mlx_xpm_file_to_image(param->mlx,
			"ray_casting/textures/s.xpm", &h, &w);
	param->image_w = mlx_xpm_file_to_image(param->mlx,
			"ray_casting/textures/wp.xpm", &h, &w);
	param->image_e = mlx_xpm_file_to_image(param->mlx,
			"ray_casting/textures/w.xpm", &h, &w);
	if (!param->image_north || !param->image_w
		|| !param->image_s || !param->image_e)
		perror("Error\nInvalide texture .. try again !!\n");
}

void	loop_mlx(t_builders *param)
{
	int	h1;
	int	w2;

	param->data_north = (unsigned int *)mlx_get_data_addr(param->image_north,
			&h1, &param->coors->size_line_north, &w2);
	param->data_s = (unsigned int *)mlx_get_data_addr(param->image_s,
			&h1, &param->coors->size_line_s, &w2);
	param->data_w = (unsigned int *)mlx_get_data_addr(param->image_w,
			&h1, &param->coors->size_line_w, &w2);
	param->data_e = (unsigned int *)mlx_get_data_addr(param->image_e,
			&h1, &param->coors->size_line_e, &w2);
	mlx_hook(param->mlx_win, 2, 1L << 0, hooking, param);
	mlx_hook(param->mlx_win, 3, 1L << 1, realising, param);
	mlx_loop_hook(param->mlx, key_hook, param);
	mlx_loop(param->mlx);
}
