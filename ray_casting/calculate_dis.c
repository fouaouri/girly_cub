/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_dis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:07:52 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/02 19:25:37 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    hori_up(t_builders  *param)
{
	if(ft_right_left(param->coors->t) == 1)
	{
		param->coors->f = param->coors->t - ((3 * PI) / 2);
		param->coors->point_x = tan(param->coors->f) * (param->coors->p_y - (int)param->coors->p_y) + param->coors->p_x;
	}
	else if(ft_right_left(param->coors->t) == -1)
	{
		param->coors->f = ((3 * PI) / 2) - param->coors->t;
		param->coors->point_x = param->coors->p_x - (tan(param->coors->f) * (param->coors->p_y - (int)param->coors->p_y));
	}
	param->coors->c = (param->coors->p_y - (int)param->coors->p_y) / cos(param->coors->f);
    param->coors->point_y = (int)param->coors->p_y;
	if(param->coors->point_y > 14)
		param->coors->point_y = 14;
	if(param->coors->point_x > 38)
		param->coors->point_x = 38;
	if(param->coors->point_y < 0)
		param->coors->point_y = 0;
	if(param->coors->point_x < 0)
		param->coors->point_x = 0;
	while(param->map[(int)param->coors->point_y - 1][(int) param->coors->point_x] != '1')
	{
		param->coors->c += 1 / cos(param->coors->f);
		if (ft_right_left(param->coors->t) == -1)
			param->coors->point_x -= tan(param->coors->f) * 1;
		else if (ft_right_left(param->coors->t) == +1)
			param->coors->point_x += tan(param->coors->f) * 1;
		param->coors->point_y -= 1;
		if(param->coors->point_y > 14)
			param->coors->point_y = 14;
		if(param->coors->point_x > 38)
			param->coors->point_x = 38;
		if(param->coors->point_y < 0)
			param->coors->point_y = 0;
		if(param->coors->point_x < 0)
			param->coors->point_x = 0;
	}
}

void    hori_down(t_builders  *param)
{
    if(ft_right_left(param->coors->t) == 1)
						{
							param->coors->f = (PI / 2) - param->coors->t;
							param->coors->point_x = tan(param->coors->f) * (((int)param->coors->p_y + 1) - param->coors->p_y) + param->coors->p_x;
						}
						else if(ft_right_left(param->coors->t) == -1)
						{
							param->coors->f = param->coors->t - (PI / 2);
							param->coors->point_x = param->coors->p_x - (tan(param->coors->f) * (((int)param->coors->p_y + 1) - param->coors->p_y));
						}
						param->coors->c = (((int)param->coors->p_y + 1) - param->coors->p_y) / cos(param->coors->f);
						param->coors->point_y = (int)param->coors->p_y;
						if(param->coors->point_y > 14)
							param->coors->point_y = 14;
						if(param->coors->point_x > 38)
							param->coors->point_x = 38;
						if(param->coors->point_y < 0)
							param->coors->point_y = 0;
						if(param->coors->point_x < 0)
							param->coors->point_x = 0;
						while(param->map[(int)param->coors->point_y + 1][(int) param->coors->point_x] != '1')
						{
							param->coors->c += 1 / cos(param->coors->f);
							if (ft_right_left(param->coors->t) == -1)
								param->coors->point_x -= tan(param->coors->f) * 1;
							else if (ft_right_left(param->coors->t) == +1)
								param->coors->point_x += tan(param->coors->f) * 1;
							param->coors->point_y += 1;
							if(param->coors->point_y > 14)
								param->coors->point_y = 14;
							if(param->coors->point_x > 38)
								param->coors->point_x = 38;
							if(param->coors->point_y < 0)
								param->coors->point_y = 0;
							if(param->coors->point_x < 0)
								param->coors->point_x = 0;
						}
}

void    vertical_down(t_builders *param)
{
    param->coors->flag = 0;
						if (ft_right_left(param->coors->t) == -1)
							param->coors->flag = -1;
						else if (ft_right_left(param->coors->t) == 1)
							param->coors->flag = 1;
						param->coors->g = param->coors->t;
						if (param->coors->flag == 1)
						{
							param->coors->g = param->coors->t;
							param->coors->c1 = (((int)param->coors->p_x + 1) - param->coors->p_x) / cos(param->coors->g);
							param->coors->point_y = (tan(param->coors->g) * (((int)param->coors->p_x + 1) - param->coors->p_x)) + param->coors->p_y;
							param->coors->point_x =(int)param->coors->p_x + 1;
						}
						else if (param->coors->flag == -1)
						{
							param->coors->g = PI - param->coors->t;
							param->coors->c1 = (param->coors->p_x - (int)param->coors->p_x) / cos(param->coors->g);
							param->coors->point_y = tan(param->coors->g) * (param->coors->p_x - (int)param->coors->p_x) + param->coors->p_y;
							param->coors->point_x =(int)param->coors->p_x;
						}
						if(param->coors->point_y > 14)
							param->coors->point_y = 14;
						if(param->coors->point_x > 38)
							param->coors->point_x = 38;
						if(param->coors->point_y < 0)
							param->coors->point_y = 0;
						if(param->coors->point_x < 0)
							param->coors->point_x = 0;
						if (param->coors->flag == -1)
						{
							while(param->map[(int)param->coors->point_y][(int)param->coors->point_x - 1] != '1')
							{
								if (param->coors->flag != -1)
									break ;
								param->coors->c1 += 1 / cos(param->coors->g);
								param->coors->point_x -= 1;
								param->coors->point_y += tan(param->coors->g) * 1;
								if(param->coors->point_y > 14)
									param->coors->point_y = 14;
								if(param->coors->point_x > 38)
									param->coors->point_x = 38;
								if(param->coors->point_y < 0)
									param->coors->point_y = 0;
								if(param->coors->point_x < 0)
									param->coors->point_x = 0;
							}
						}
						else if (param->coors->flag == 1)
						{
							while(param->map[(int)param->coors->point_y][(int) param->coors->point_x] != '1')
							{
								if (param->coors->flag != 1)
									break ;
								param->coors->c1 += 1 / cos(param->coors->g);
								param->coors->point_x += 1;
								param->coors->point_y += tan(param->coors->g) * 1;
								if(param->coors->point_y > 14)
									param->coors->point_y = 14;
								if(param->coors->point_x > 38)
									param->coors->point_x = 38;
								if(param->coors->point_y < 0)
									param->coors->point_y = 0;
								if(param->coors->point_x < 0)
									param->coors->point_x = 0;
							}
						}
}

void    vertical_up(t_builders *param)
{
    param->coors->flag = 0;
						if (ft_right_left(param->coors->t) == -1)
							param->coors->flag = -1;
						else if (ft_right_left(param->coors->t) == 1)
							param->coors->flag = 1;
						if (param->coors->flag == -1)
						{
							param->coors->g = param->coors->t - PI;
							param->coors->c1 = (param->coors->p_x - (int)param->coors->p_x) / cos(param->coors->g);
							param->coors->point_y = param->coors->p_y - (tan(param->coors->g) * (param->coors->p_x - (int)param->coors->p_x));
						}
						else if (param->coors->flag == 1)
						{
							param->coors->g = (2 * PI) - param->coors->t;
							param->coors->c1 = ((int)param->coors->p_x + 1  -  param->coors->p_x ) / cos(param->coors->g);
							param->coors->point_y = param->coors->p_y - (tan(param->coors->g) * ((int)param->coors->p_x + 1  -  param->coors->p_x));
						}
						param->coors->point_x = (int)param->coors->p_x;
						if(param->coors->point_y > 14)
							param->coors->point_y = 14;
						if(param->coors->point_x > 38)
							param->coors->point_x = 38;
						if(param->coors->point_y < 0)
							param->coors->point_y = 0;
						if(param->coors->point_x < 0)
							param->coors->point_x = 0;
						if (param->coors->flag == -1)
						{
							while(param->map[(int)param->coors->point_y][(int) param->coors->point_x - 1] != '1')
							{
								if (param->coors->flag != -1)
									break ;
								param->coors->c1 += 1 / cos(param->coors->g);
								param->coors->point_x -= 1;
								param->coors->point_y -= tan(param->coors->g) * 1;
								if(param->coors->point_y > 14)
									param->coors->point_y = 14;
								if(param->coors->point_x > 38)
									param->coors->point_x = 38;
								if(param->coors->point_y < 0)
									param->coors->point_y = 0;
								if(param->coors->point_x < 0)
									param->coors->point_x = 0;
							}
						}
						else if (param->coors->flag == 1)
						{
							while(param->map[(int)param->coors->point_y][(int) param->coors->point_x + 1] != '1')
							{
								if (param->coors->flag != 1)
									break ;
								param->coors->c1 += 1 / cos(param->coors->g);
								param->coors->point_x += 1;
								param->coors->point_y -= tan(param->coors->g) * 1;
								if(param->coors->point_y > 14)
									param->coors->point_y = 14;
								if(param->coors->point_x > 38)
									param->coors->point_x = 38;
								if(param->coors->point_y < 0)
									param->coors->point_y = 0;
								if(param->coors->point_x < 0)
									param->coors->point_x = 0;								
							}
						}
}

void	draw_mini_map(t_builders *param)
{
	int i = 0;
	int j = 0;
	int h = 0;
	int w = 0;
	while (param->map[i])
	{
		j = 0;
		while(param->map[i][j])
		{
			if(param->map[i][j] == '1')
			{
				w = 1;
				while(w < UNIT_SIZE)
				{
					h = 1;
					while(h < UNIT_SIZE)
					{
						data_value(param, i * UNIT_SIZE + w, j * UNIT_SIZE + h, PINKY_PIXEL);
						h++;
					}
					w++;
				}
			}
			if(param->map[i][j] == '0' || param->map[i][j] == 'P')
			{
				w = 1;
				while (w < UNIT_SIZE)
				{
					h = 1;
					while(h < UNIT_SIZE)
					{
						data_value(param, i * UNIT_SIZE + w, j * UNIT_SIZE + h, WHITE_PIXEL);
						h++;
					}
					w++;
				}
			}
				w = 14;
				while(w < 18)
				{
					h = 14;
					while(h < 18)
					{
						data_value(param, (param->coors->p_y - 1.5)  * UNIT_SIZE + w, (param->coors->p_x - 1.5)* UNIT_SIZE + h, PINK_PIXEL);
						h++;
					}
					w++;
				}
			
				j++;
		}
		i++;
	}
}

void    draw_rays(t_builders *param)
{
    param->coors->f = 0;
	param->coors->g = 0;
	param->coors->c = 0;
	param->coors->r = 0;
	param->coors->c1 = 0;
	param->coors->point_x = 0;
	param->coors->point_x1 = 0;
	param->coors->point_y = 0;
					// hori
	if (ft_up_down(param->coors->t) == -1)
		hori_up(param);
	else if (ft_up_down(param->coors->t) == 1)
		hori_down(param);
					// vert
	param->coors->point_x1 = param->coors->point_x;
	if (ft_up_down(param->coors->t) == 1)
		vertical_down(param);
    else if (ft_up_down(param->coors->t) == -1)
		vertical_up(param);
	if (param->coors->c <= param->coors->c1)
	{
		if(ft_up_down(param->coors->t) == -1)
			param->coors->direc = 'n';
		else
			param->coors->direc = 's';
		param->coors->r = param->coors->c;
	}
	else if (param->coors->c1 <= param->coors->c)
	{
		if(ft_right_left(param->coors->t) == -1)
			param->coors->direc = 'w';
		else
			param->coors->direc = 'e';
		param->coors->r = param->coors->c1;
	}
	int w = 0;
	while(w < param->coors->r * UNIT_SIZE)
	{
		data_value(param, (param->coors->p_y * UNIT_SIZE)  + (w * sin(param->coors->t)), (param->coors->p_x * UNIT_SIZE)  + (w * cos(param->coors->t)), BLUE_PIXEL);
			w += 1;
	}
}