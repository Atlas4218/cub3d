/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:16:15 by rastie            #+#    #+#             */
/*   Updated: 2023/12/08 16:42:21 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	is_floor(char **map, int i, int j)
{
	if (i < 0 || j < 0)
		return (0);
	return (map[i][j] == '0');
}

void	draw_map(t_data *data)
{
	t_vector	player;
	t_img		*img;
	int			i;
	int			j;

	img = data->ray.ray_ptr;
	player = data->ray;
	i = (player.posy - 2.5) * 100 - 1;
	while (++i <= (player.posy + 2.5) * 100)
	{
		j = (player.posx - 2.5) * 100;
		while (j <= (player.posx + 2.5) * 100)
		{
			if (i / 100 < data->nb_line_map && j / 100 < data->lenmax
				&& is_floor(data->map, (int)i / 100, (int)j / 100))
				my_mlx_pixel_put(
					j++ - (player.posx - 2.5) * 100,
					i - (player.posy - 2.5) * 100, img,
					0xffffff);
			else
				my_mlx_pixel_put(j++ - (player.posx - 2.5) * 100,
					i - (player.posy - 2.5) * 100, img,
					0x5e505e);
		}
	}
}

int	gest_minimap(t_data *data)
{
	t_vector	player;
	t_circle	point;
	t_line		line;
	t_img		*img;

	player = data->ray;
	(void)player;
	img = data->ray.ray_ptr;
	point = (struct s_circle){250, 250, 05};
	if (player.diry > 0)
		player.angle += 180;
	line = (struct s_line){250, 250, 20, player.angle};
	draw_map(data);
	draw_circle(point, img, 0x000000);
	draw_line(line, img, 0x000000);
	return (0);
}
