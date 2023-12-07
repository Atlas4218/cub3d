/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:31:13 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/07 18:15:48 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
*	Calcule si en fonction de la vitesse de deplacement et de la direction
	du regard le mouvement ne sors pas des limites autorise
*/

void	move_forward_backward(t_data *data)
{
	float	new_posx;
	float	new_posy;

	if (data->forward == 1)
	{
		new_posx = data->ray.posx + data->ray.dirx * data->ray.movespeed;
		new_posy = data->ray.posy + data->ray.diry * data->ray.movespeed;
		if (is_valid_move_x(data, new_posx))
			data->ray.posx = new_posx;
		if (is_valid_move_y(data, new_posy))
			data->ray.posy = new_posy;
	}
	if (data->backward == 1)
	{
		new_posx = data->ray.posx - data->ray.dirx * data->ray.movespeed;
		new_posy = data->ray.posy - data->ray.diry * data->ray.movespeed;
		if (is_valid_move_x(data, new_posx))
			data->ray.posx = new_posx;
		if (is_valid_move_y(data, new_posy))
			data->ray.posy = new_posy;
	}
}

void	strafe_right_left(t_data *data)
{
	float	new_posx;
	float	new_posy;

	if (data->strafeleft == 1)
	{
		new_posx = data->ray.posx - data->ray.planex * data->ray.movespeed;
		new_posy = data->ray.posy - data->ray.planey * data->ray.movespeed;
		if (is_valid_move_x(data, new_posx))
			data->ray.posx = new_posx;
		if (is_valid_move_y(data, new_posy))
			data->ray.posy = new_posy;
	}
	if (data->straferight == 1)
	{
		new_posx = data->ray.posx + data->ray.planex * data->ray.movespeed;
		new_posy = data->ray.posy + data->ray.planey * data->ray.movespeed;
		if (is_valid_move_x(data, new_posx))
			data->ray.posx = new_posx;
		if (is_valid_move_y(data, new_posy))
			data->ray.posy = new_posy;
	}
}

/*
*	additionne ou soustrait une incrementation d'angle
*	a l'angle de vision actuel du joueur
*/

void	rotate_right(t_data *data)
{
	float	olddirx;
	float	oldplanex;

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
	data->ray.angle = acos(data->ray.dirx) * (180 / M_PI);
}

void	rotate_left(t_data *data)
{
	float	olddirx;
	float	oldplanex;

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
	data->ray.angle = acos(data->ray.dirx) * (180 / M_PI);
}
