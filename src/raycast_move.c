/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:31:13 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/29 11:42:01 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	move_forward_backward(t_data *data)
{
	if (data->forward == 1)
	{
		if (data->map[(int)(data->ray.posx + (data->ray.dirx
					* data->ray.movespeed))][(int)data->ray.posy] == '0')
			data->ray.posx += data->ray.dirx * data->ray.movespeed;
		if (data->map[(int)data->ray.posx][(int)(data->ray.posy
			+ (data->ray.diry * data->ray.movespeed))] == '0')
			data->ray.posy += data->ray.diry * data->ray.movespeed;
	}
	if (data->backward == 1)
	{
		if (data->map[(int)(data->ray.posx - (data->ray.dirx
					* data->ray.movespeed))][(int)data->ray.posy] == '0')
			data->ray.posx -= data->ray.dirx * data->ray.movespeed;
		if (data->map[(int)data->ray.posx][(int)(data->ray.posy
			- (data->ray.diry * data->ray.movespeed))] == '0')
			data->ray.posy -= data->ray.diry * data->ray.movespeed;
	}
}

void	strafe_right_left(t_data *data)
{
	if (data->strafeleft == 1)
	{
		if (data->map[(int)(data->ray.posx - (data->ray.planex
					* data->ray.movespeed))][(int)data->ray.posy] == '0')
			data->ray.posx -= data->ray.planex * data->ray.movespeed;
		if (data->map[(int)data->ray.posx][(int)(data->ray.posy
			- (data->ray.planey * data->ray.movespeed))] == '0')
			data->ray.posy -= data->ray.planey * data->ray.movespeed;
	}
	if (data->straferight == 1)
	{
		if (data->map[(int)(data->ray.posx + (data->ray.planex
					* data->ray.movespeed))][(int)data->ray.posy] == '0')
			data->ray.posx += data->ray.planex * data->ray.movespeed;
		if (data->map[(int)data->ray.posx][(int)(data->ray.posy
			+ data->ray.planey * (data->ray.movespeed))] == '0')
			data->ray.posy += data->ray.planey * data->ray.movespeed;
	}
}

void	rotate_right(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->ray.dirx;
	oldplanex = data->ray.planex;
	if (data->rotateright == 1)
	{
		data->ray.dirx = data->ray.dirx * cos(-data->ray.rotspeed)
			- data->ray.diry * sin(-data->ray.rotspeed);
		data->ray.diry = olddirx * sin(-data->ray.rotspeed)
			+ data->ray.diry * cos(-data->ray.rotspeed);
		data->ray.planex = data->ray.planex * cos(-data->ray.rotspeed)
			- data->ray.planey * sin(-data->ray.rotspeed);
		data->ray.planey = oldplanex * sin(-data->ray.rotspeed)
			+ data->ray.planey * cos(-data->ray.rotspeed);
	}
}

void	rotate_left(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->ray.dirx;
	oldplanex = data->ray.planex;
	if (data->rotateleft == 1)
	{
		data->ray.dirx = data->ray.dirx * cos(data->ray.rotspeed)
			- data->ray.diry * sin(data->ray.rotspeed);
		data->ray.diry = olddirx * sin(data->ray.rotspeed)
			+ data->ray.diry * cos(data->ray.rotspeed);
		data->ray.planex = data->ray.planex * cos(data->ray.rotspeed)
			- data->ray.planey * sin(data->ray.rotspeed);
		data->ray.planey = oldplanex * sin(data->ray.rotspeed)
			+ data->ray.planey * cos(data->ray.rotspeed);
	}
}
