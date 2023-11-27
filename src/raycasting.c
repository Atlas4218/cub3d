/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:33:58 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/27 17:48:32 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
*	Initialisation et protection de DeltaDist (distance entre deux cote x ou y d'un carre en fontion du joueur)
*/

void	deltadist_init(t_data *data)
{
	if (data->ray.raydiry == 0)
		data->ray.deltadistx = 0;
	else if (data->ray.raydirx == 0)
			data->ray.deltadistx = 1;
	else
		data->ray.deltadistx = sqrt(1 + (data->ray.raydiry * data->ray.raydiry)
				/ (data->ray.raydirx * data->ray.raydirx));
	if (data->ray.raydirx == 0)
		data->ray.deltadisty = 0;
	else if (data->ray.raydiry == 0)
		data->ray.deltadisty = 1;
	else
		data->ray.deltadisty = sqrt(1 + (data->ray.raydirx * data->ray.raydirx)
				/ (data->ray.raydiry * data->ray.raydiry));
}

void	draw_walls(t_data *data, int x, int y)
{
	int	color;
	char cell_value = data->map[x][y];

	if (cell_value == '1')
		color = 0xFFFFFF;
	y = data->ray.drawstart - 1;
	while (y <= data->ray.drawend)
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, color);
		y++;
	}
}

void	draw_column(t_data *data)
{
	int	y;

	y = 0;
	data->ray.drawend = data->screen_height - data->ray.drawstart;
	while (y < data->ray.drawstart)
		y++;
	if (y <= data->ray.drawend)
			draw_walls(data, data->ray.x, y);
	return ;
}

/*
*	fonction global d'ou part les different calcul de raycasting pour etre gerer par mlx_loop_hook
*/
int	raycasting(t_data *data)
{
	data->ray.x = 0;
	while (data->ray.x < data->screen_width)
	{
		data->ray.camerax = 2 * data->ray.x / (double)data->screen_width - 1;
		data->ray.raydirx = data->ray.dirx
			+ data->ray.planex *  data->ray.camerax;
		data->ray.raydiry = data->ray.diry
			+ data->ray.planey *  data->ray.camerax;
		data->ray.perpwalldist = 0;
		data->ray.hit = 0;
		data->ray.movespeed = 0.1;
		data->ray.rotspeed = 0.033 * 1.8;
		deltadist_init(data);
		steps_side_dist(data);
		draw_column(data);
		data->ray.x++;
	}
	move_forward_backward(data);
	strafe_right_left(data);
	rotate_right(data);
	rotate_left(data);
	return (0);
}
