/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 03:13:06 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/05 15:30:42 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	get_dementions(char *av, t_builders *param)
{
	int			fd;
	int			i;
	char		*line;

	fd = (open(av, O_RDONLY));
	if(!fd)
		return ;
	param->line = ft_calloc(1, 1);
	while (1)
	{
		line = get_next_line(fd);
		param->coors->height++;
		if (!line)
			break ;
		param->line = ft_strjoin(param->line, line);
		free(line);
	}
	i = 0;
	param->coors->height -= 1;
	while (param->line[i] != '\n' && param->line[i] != '\0')
		i++;
	param->coors->width = i;
}

char	**get_map(char *av, t_builders *param)
{
	int		index;
	char	*line;
	char	**all;
	int		fd;

	index = 0;
	fd = open(av, O_RDONLY);
	all = ft_calloc(sizeof(char *), (param->coors->height + 1));
	while (1)
	{
		line = get_next_line(fd);
		all[index++] = line;
		if (line == NULL)
			break ;
	}
	close(fd);
	return (all);
}

void	put_img(t_builders *param, int key, int x, int y)
{
	int	pose;

	pose = (y * param->coors->size_line / 4) + x;
	if (pose >= (1200 * 800))
		return ;
	else if (pose < 0)
		return ;
	param->data[pose] = key;
}
void	pose_player(t_builders *param)
{
	double	w;

	w = 0;
	param->coors->t = param->coors->turn_direc - (PI / 6);
	double a = 0;
	double i1 = 0;
	while (i1 <= 1.0471975512)
	{
		return_after_2_pi1(param);
		draw_rays(param);
		// param->coors->di_player_projection = (WIN_WIDTH / 2) / (2 *  tan (PI / 6));
		// param->coors->proj_wall_height = (30 / (param->coors->r * 30) * param->coors->di_player_projection);
		// param->coors->wall_height = (int)param->coors->proj_wall_height;
		double j = 0;
		double wall_len = 800 / (param->coors->r * cos(param->coors->turn_direc - param->coors->t));
		double wall_len2 =wall_len;
		double i = 400 - wall_len / 2;
		if (wall_len > 800)
		{
			j = wall_len2 / 2 - 550;
			if (j < 0)
				j = 0;
			wall_len2 = wall_len2 / 2 + 400;
		}
		// if (param->coors->wall_height > 800)
		// 	param->coors->wall_height = 800;
		// if(param->coors->wall_height > 800)
		// 	param->coors->wall_height = 800;	
		// param->coors->top_pixel = (WIN_HEIGHT / 2) - (param->coors->wall_height / 2);
		// if (param->coors->top_pixel < void	pars_part(int ac, char **av)0)
		// 	param->coors->top_pixel = 0;
		// param->coors->bottom_pixel = (WIN_HEIGHT / 2) + (param->coors->wall_height / 2);
		// if (param->coors->bottom_pixel > WIN_HEIGHT)
		// 	param->coors->bottom_pixel = WIN_HEIGHT;
		// double l = 0;
		// double m = 400 - param->coors->wall_height / 2;
		// printf("%f\n",param->coors->wall_height);
		while(j <= wall_len2)
		{
			// printf("-->point : %f\n", param->coors->point_y);
			int color;
			if(param->coors->direc == 'n') 
			{
				color= (((int)(j * 250 / wall_len) % 250)* (param->coors->size_line_north / 4)) + (param->coors->point_x1 - (int)param->coors->point_x1) *  250;
				put_img(param, param->data_north[color],a,i + j);
			}
			else if(param->coors->direc == 's')
			{
				color= (((int)(j * 250 / wall_len) % 250)* (param->coors->size_line_s / 4)) + (param->coors->point_x1 - (int)param->coors->point_x1) *  250;
				put_img(param, param->data_s[color],a,i + j);
			}else if(param->coors->direc == 'w')
			{
				color= (((int)(j * 250 / wall_len) % 250)* (param->coors->size_line_w / 4)) + (param->coors->point_y - (int)param->coors->point_y) *  250;
				put_img(param, param->data_w[color],a,i + j);
			}else if(param->coors->direc == 'e')
			{
				color= (((int)(j * 250 / wall_len) % 250)* (param->coors->size_line_e/ 4)) + (param->coors->point_y - (int)param->coors->point_y) *  250;
				put_img(param, param->data_e[color],a,i + j);
			}
			j += 1;
		}
		param->coors->t += 0.00087266462;
		a += 1;
		i1 += 0.00087266462;
	}
}

int main(int ac, char **av)
{
	int i = 0;
	t_builders *param;
	t_coordinates	coor;
	t_mystruct pars;
	param = malloc(sizeof(t_builders));

	pars_part(ac, av, &pars);
	// param->coors = &coor;
	// param->pars = &pars;
	// param->moves = 0;
	// param->coors->height = 0;
	// param->coors->turn_direc = 0;
	// param->coors->direction = 0;
	// param->coors->b = 0;
	// param->image = NULL;	
	// param->image_north = NULL;
	// param->up_down= -1;
	// param->view = 0;
    // get_dementions(av[1], param);
	// param->map = get_map(av[1], param);

	// while(param->pars->map[i])
	// {
	// 	printf ("%s", param->pars->map[i]);
	// 	i++;
	// }		
	
	// int j = 0;
	// i = 0;
	// printf("0 : %s\n", param->pars->map[0]);
	
	// while (param->map[i])
	// {
	// 	j = 0;
	// 	while(param->map[i][j])
	// 	{
	// 		if(param->map[i][j] == 'P')
	// 		{
	// 			param->coors->p_x = j + 0.5;
	// 			param->coors->p_y = i + 0.5;
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	
	// int	h;
	// int	w;
	// param->mlx = mlx_init();
	// param->mlx_win = mlx_new_window(param->mlx, WIN_WIDTH, WIN_HEIGHT, "CHAMA");
	// param->image_north =mlx_xpm_file_to_image(param->mlx,"ray_casting/n.xpm",&h,&w);
	// param->image_s =mlx_xpm_file_to_image(param->mlx,"ray_casting/s.xpm",&h,&w);
	// param->image_w =mlx_xpm_file_to_image(param->mlx,"ray_casting/w.xpm",&h,&w);
	// param->image_e =mlx_xpm_file_to_image(param->mlx,"ray_casting/e.xpm",&h,&w);
	// int	h1;
	// int	w2;
	// param->data_north = (unsigned int * )mlx_get_data_addr(param->image_north,&h1,&param->coors->size_line_north,&w2);
	// param->data_s= (unsigned int * )mlx_get_data_addr(param->image_s,&h1,&param->coors->size_line_s,&w2);
	// param->data_w = (unsigned int * )mlx_get_data_addr(param->image_w,&h1,&param->coors->size_line_w,&w2);
	// param->data_e = (unsigned int * )mlx_get_data_addr(param->image_e,&h1,&param->coors->size_line_e,&w2);
	// mlx_hook(param->mlx_win, 2, 1L<<0, hooking, param);
	// mlx_hook(param->mlx_win, 3, 1L<<1, realising, param);
	// mlx_loop_hook(param->mlx, key_hook, param);
    // mlx_loop(param->mlx);
}
