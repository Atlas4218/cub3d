/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:33:58 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/07 14:29:58 by rastie           ###   ########.fr       */
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
	y = data->ray.drawstart - 1;
	init_texture(data);
	data->tex.step = 1.0 * data->texture[0].height / data->ray.lineheight;
	data->tex.texx = (int)(data->tex.wallx
			* (float)data->texture[data->tex.texdir].width);
	if (data->ray.side == 0 && data->ray.raydirx > 0)
		data->tex.texx = data->texture[data->tex.texdir].width
			- data->tex.texx - 1;
	if (data->ray.side == 1 && data->ray.raydiry < 0)
		data->tex.texx = data->texture[data->tex.texdir].width
			- data->tex.texx - 1;
	data->tex.texpos = (data->ray.drawstart - data->screen_height / 2
			+ data->ray.lineheight / 2) * data->tex.step;
	while (++y <= data->ray.drawend)
	{
		data->tex.texy = (int)data->tex.texpos &(data
				->texture[data->tex.texdir].height - 1);
		data->tex.texpos += data->tex.step;
		if (y < data->screen_height && x < data->screen_width)
			data->ray.data_addr[y * data->ray.size_l / 4 + x]
				= data->texture[data->tex.texdir].addr[data->tex.texy
				* data->texture[data->tex.texdir].size_l / 4 + data->tex.texx];
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

void	draw_background(t_data *data)
{
	t_img	*vision;
	int		i;
	int		j;

	vision = data->ray.ray_ptr;
	i = 0;
	while (i <= vision->height)
	{
		j = 0;
		while (j <= vision->width)
		{
			if (i < vision->height / 2)
				my_mlx_pixel_put(j++, i, vision, data->ceiling);
			else
				my_mlx_pixel_put(j++, i, vision, data->floor);
		}
		i++;
	}
}

/*
*	fonction global d'ou part les different calcul de raycasting pour etre gerer par mlx_loop_hook
*/
int	raycasting(t_data *data)
{
	data->ray.x = 0;
	draw_background(data);
	if (data->map[(int)data->ray.posy][(int)data->ray.posx] == '0')
	{
		while (data->ray.x < data->screen_width)
		{
			raycasting_init(data);
			deltadist_init(data);
			steps_side_dist(data);
			draw_column(data);
			data->ray.x++;
		}
	}
	gest_minimap(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->ray.ray_ptr, 0, 0);
	move_forward_backward(data);
	strafe_right_left(data);
	rotate_right(data);
	rotate_left(data);
	return (0);
}
