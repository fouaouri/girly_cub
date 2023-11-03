/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_turn_direc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <fouaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:22:35 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/02 19:25:54 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	return_after_2_pi(t_builders param)
{
	if (param.coors->turn_direc > 2 * PI)
		param.coors->turn_direc -= 2 * PI;
	else if (param.coors->turn_direc < 0)
		param.coors->turn_direc += 2 * PI;
}

void	return_after_2_pi1(t_builders *param)
{
	if (param->coors->t > 2 * PI)
		param->coors->t -= 2 * PI;
	else if (param->coors->t < 0)
		param->coors->t += 2 * PI;
}

int	ft_up_down(double t)
{
	int flag; 
	
	flag = 0;
	if (t >= 0 && t <= PI)
		return (1);
	else if (t > PI && t <= (2 * PI))
		return (-1);
	return (0);
}

int	ft_right_left(double t)
{
	int flag; 
	
	flag = 0;
	if ((t >= (3 * PI) / 2 && t <= 2 * PI)
		|| (t >= 0 && t < PI / 2))
		return (1);
	else if (t >= PI / 2 && t < (3 * PI) / 2)
		return (-1);  
	return (0);
}