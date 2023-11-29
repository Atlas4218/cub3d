/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:37:51 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/29 16:55:27 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	init_player(t_data *data, int x, int y, char c)
{
	data->ray.angle = get_angle(c);
	data->ray.posx = x;
	data->ray.posy = y;
	get_vector_dir(data->ray.angle, data->ray.dirx, data->ray.diry);
	data->ray.planex = 0;
	data->ray.planey = 0.66;
}

int	init_map(t_data *data)
{
	data->map = get_map(data->mappath);
	if (!data->map)
		return (closer(data));
	if (parse_map(data->map, data))
		return (closer(data));
	return (0);
}

int	init_win(t_data *data)
{
	if (init_map(data))
		return (closer(data));
	return (0);
}

int	init_wall(t_data *data)
{
	data->wallno = mlx_xpm_file_to_image(data->mlx,
			"asset/img/wallno.xpm", &(data->x), &data->y);
	if (!data->wallno)
		return (closer(data));
	data->wallso = mlx_xpm_file_to_image(data->mlx,
			"asset/img/wallso.xpm", &(data->x), &data->y);
	if (!data->wallso)
		return (closer(data));
	data->wallea = mlx_xpm_file_to_image(data->mlx,
			"asset/img/wallea.xpm", &(data->x), &data->y);
	if (!data->wallea)
		return (closer(data));
	data->wallwe = mlx_xpm_file_to_image(data->mlx,
			"asset/img/wallwe.xpm", &(data->x), &data->y);
	if (!data->wallwe)
		return (closer(data));
	return (0);
}

int	init_data(t_data *data)
{
	if (!data)
		return (closer(data));
	ft_bzero(data, sizeof (*data));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (closer(data));
	init_wall(data);
	data->floor = mlx_xpm_file_to_image(data->mlx,
			"asset/img/floor.xpm", &(data->x), &data->y);
	if (!data->floor)
		return (closer(data));
	data->ceiling = mlx_xpm_file_to_image(data->ceiling,
			"asset/img/celling.xpm", &(data->x), &data->y);
	//mlx_get_screen_size(data->mlx, &(data->swidth), &(data->sheight));
	//if (!data->swidth || !data->sheight)
	//	return (closer(data));
	return (init_win(data));
}
