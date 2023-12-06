/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:16:15 by rastie            #+#    #+#             */
/*   Updated: 2023/12/06 17:53:52 by gbonnard         ###   ########.fr       */
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

	img = data->img_map;
	player = data->ray;
	i = (player.posy - 2.5) * 100 - 1;
	while (++i <= (player.posy + 2.5) * 100)
	{
		j = (player.posx - 2.5) * 100;
		while (j <= (player.posx + 2.5) * 100)
		{
			if (is_floor(data->map, (int)i / 100, (int)j / 100))
				my_mlx_pixel_put(
					j++ - (player.posx - 2.5) * 100,
					i - (player.posy - 2.5) * 100, img,
					data->floor);
			else
				my_mlx_pixel_put(j++ - (player.posx - 2.5) * 100,
					i - (player.posy - 2.5) * 100, img,
					inv_color(data->floor));
		}
	}
}

int	gest_minimap(t_data *data)
{
	t_vector	player;
	t_line		dir;
	t_circle	point;
	t_img		*img;

	player = data->ray;
	(void)player;
	img = data->img_map;
	dir = (struct s_line){250, 250, 40, 0, 290};
	point = (struct s_circle){250, 250, 20};
	draw_map(data);
	draw_circle(point, img, inv_color(data->floor));
	draw_line(dir, img, inv_color(data->floor));
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, 0, 0);
	return (0);
}

void	minimap(t_data *data)
{
	data->img_map = mlx_new_image(data->mlx, 500, 500);
	gest_minimap(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_map, 0, 0);
}
