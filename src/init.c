/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:37:51 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/06 18:00:06 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_player(t_data *data, int x, int y, char c)
{
	data->ray.angle = get_angle(c, data);
	data->ray.posx = (float)x + 0.5;
	data->ray.posy = (float)y + 0.5;
	get_vector_dir(data->ray.angle, &data->ray.dirx, &data->ray.diry);
	mlx_get_screen_size(data->mlx, &data->screen_width, &data->screen_height);
}

int	init_file(t_data *data)
{
	data->file = get_file(data->mappath);
	if (!data->file)
		return (closer(data));
	if (parse_file(data->file, data))
		return (closer(data));
	return (0);
}

int	init_win(t_data *data)
{
	if (init_file(data))
		return (closer(data));
	data->img_map = mlx_new_image(data->mlx, 500, 500);
	if (!data->img_map)
		return (closer(data));
	return (0);
}

void	init_texture(t_data *data)
{
	if (data->ray.side == 0 && data->ray.raydirx < 0)
		data->tex.texdir = 0;
	if (data->ray.side == 0 && data->ray.raydirx >= 0)
		data->tex.texdir = 1;
	if (data->ray.side == 1 && data->ray.raydiry < 0)
		data->tex.texdir = 2;
	if (data->ray.side == 1 && data->ray.raydiry >= 0)
		data->tex.texdir = 3;
	if (data->ray.side == 0)
		data->tex.wallx = data->ray.posy + data->ray.perpwalldist
			* data->ray.raydiry;
	else
		data->tex.wallx = data->ray.posx + data->ray.perpwalldist
			* data->ray.raydirx;
	data->tex.wallx -= floor(data->tex.wallx);
}

int	init_data(t_data *data)
{
	if (!data)
		return (closer(data));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (closer(data));
	return (init_win(data));
}
