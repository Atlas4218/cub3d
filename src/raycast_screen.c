/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:32:01 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/06 17:55:58 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
*	Empeche l'effet de FishEye et calcul la distance d'affichage et donc la taille visible des murs
*/
void	draw_start_end(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perpwalldist = ((float)data->ray.mapx - data->ray.posx
				+ (1 - (float)data->ray.stepx) / 2) / data->ray.raydirx;
	else
		data->ray.perpwalldist = ((float)data->ray.mapy - data->ray.posy
				+ (1 - (float)data->ray.stepy) / 2) / data->ray.raydiry;
	data->ray.lineheight = (int)(data->screen_height / data->ray.perpwalldist);
	data->ray.drawstart = -data->ray.lineheight / 2 + data->screen_height / 2;
	if (data->ray.drawstart < 0)
		data->ray.drawstart = 0;
	data->ray.drawend = data->ray.lineheight / 2 + data->screen_height / 2;
	if (data->ray.drawend >= data->screen_height || data->ray.drawend < 0)
		data->ray.drawend = data->screen_height - 1;
}

/*
*	Calcule la distance total qui separe le joueur d'un mur et quel cote du mur est touche par son regard
*/
void	increment_steps(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltadistx;
			if (data->ray.mapx < data->lenmax)
				data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			if (data->ray.mapy < data->lenmax)
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapy][data->ray.mapx] == '1')
			data->ray.hit = 1;
	}
	draw_start_end(data);
}

/*
*	Calcule la direction du joueur et la distance qui le separe du prochain carre de map
*/
void	steps_side_dist(t_data *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->ray.posx
				- data->ray.mapx) * data->ray.deltadistx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = (data->ray.mapx + 1.0
				- data->ray.posx) * data->ray.deltadistx;
	}
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->ray.posy
				- data->ray.mapy) * data->ray.deltadisty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = (data->ray.mapy + 1.0
				- data->ray.posy) * data->ray.deltadisty;
	}
	increment_steps(data);
}
