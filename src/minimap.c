/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:16:15 by rastie            #+#    #+#             */
/*   Updated: 2023/12/05 12:52:45 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	my_mlx_pixel_put(int x, int y, t_img *img, int color)
{
	int	i;

	if ((x < 0) || (x >= img->width) || (y < 0) || (y >= img->height))
		return ;
	i = (y * img->size_line) + (x * (img->bpp / 8));
	*(unsigned int *)&img->data[i] = color;
}

void	draw_circle(t_img *img, int x, int y, int r, int color)
{
	int	i;
	int	j;

	i = r - x;
	while (i <= x + r)
	{
		j = r - y;
		while (j <= y + r)
		{
			if ((pow(i - x, 2) + pow(j - y, 2)) <= pow(r, 2))
				my_mlx_pixel_put(i, j, img, color);
			j++;
		}
		i++;
	}
}

void draw_line(int x, int y, int length, t_img *img, int color, int angle)
{
	int end_x;
	int i;
	int j;

	end_x = x + length * cos(angle * M_PI / 180.0);
	i = x;
	j = y;
	if (angle != 90.0 && angle != 270.0)
		while (i <= end_x)
		{
			j = y + (i - x) * tan(angle * M_PI / 180.0);
			my_mlx_pixel_put(i++, j, img, color);
		}
	else
		while (j >= y - length)
			my_mlx_pixel_put(i, j--, img, color);
}

/* les coos du joueur sont des float
   changer ces float en int en multipliant par la taille de l'image
 */
int	is_floor(char **map, int i, int j)
{
	if (i < 0 || j < 0)
		return (0);
	return (map[i][j] == '0');
}
int	draw_map(t_data *data)
{
	t_vector	player;
	t_img	*img;
	int	i;
	int	j;

	img = data->img_map;
	player = data->ray;
	i  = (player.posy - 2.5) * 100 - 1;
	while (++i <= (player.posy + 2.5) * 100)
	{
		j = (player.posx - 2.5) * 100;
		while (j <= (player.posx + 2.5) * 100)
			if (is_floor(data->map, (int)i / 100, (int)j / 100))
				my_mlx_pixel_put(
					j++ - (player.posx - 2.5) * 100,
					i - (player.posy - 2.5) * 100,img,
					data->floor);
			else
				my_mlx_pixel_put(j++ - (player.posx - 2.5) * 100,
					i - (player.posy - 2.5) * 100, img,
					opposite_color(data->floor));
	}
	draw_circle(img, 250, 250, 30, opposite_color(data->floor));
	draw_line(250, 250, 50, img, opposite_color(data->floor), player.angle);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, 0, 0);
	return (0);
}
