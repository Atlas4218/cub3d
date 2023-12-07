/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:28:35 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/07 13:04:17 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	is_valid_move_x(t_data *data, float new_posx)
{
	int	map_value;

	if (new_posx < 0)
		return (0);
	map_value = data->map[(int)data->ray.posy][(int)new_posx];
	return (map_value);
}

int	is_valid_move_y(t_data *data, float new_posy)
{
	int	map_value;

	if (new_posy < 0 || new_posy >= data->nb_line_map)
		return (0);
	map_value = data->map[(int)new_posy][(int)data->ray.posx];
	return (map_value);
}

void	raycasting_init(t_data *data)
{
	data->ray.camerax = 2 * data->ray.x / (float)data->screen_width - 1;
	data->ray.raydirx = data->ray.dirx
		+ data->ray.planex * data->ray.camerax;
	data->ray.raydiry = data->ray.diry
		+ data->ray.planey * data->ray.camerax;
	data->ray.mapx = (int)data->ray.posx;
	data->ray.mapy = (int)data->ray.posy;
	data->ray.perpwalldist = 0;
	data->ray.hit = 0;
	data->ray.movespeed = 0.05;
	data->ray.rotspeed = 0.055;
}
