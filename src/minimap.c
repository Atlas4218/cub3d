/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:16:15 by rastie            #+#    #+#             */
/*   Updated: 2023/12/01 18:34:06 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(int x, int y, t_img *img, int color)
{
	int	i;

	if ((x < 0) || (x >= img->width) || (y < 0) || (y >= img->height))
		return ;
	i = (y * img->line_size) + (x * (img->bpp / 8));
	*(unsigned int *)&img->data_address[i] = color;
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

void draw_line(int x, int y, int length, int img, int color, double angle)
{
	int end_x;
	int end_y;
	int i;
	int j;

	end_x = x + length * cos(angle * M_PI / 180.0);
	end_y = y - length * sin(angle * M_PI / 180.0);
	i = x;
	if (angle != 90.0 && angle != 270.0)
		while (i <= end_x)
		{
			j = y + (i - x) * tan(angle * M_PI / 180.0);
			my_mlx_pixel_put(i, j, img, color);
			i++;
		}
	else
		while ((j = y - length) <= y + length)
			my_mlx_pixel_put(i, j++, img, color);
}

void	draw_map(t_data *data, t_img *img)
{
	t_vector	*player;

	player = data->ray;
	// recuperation des coos du joueur
	int	i = 0;
	int	j;
	while (i <= player->posx + 300)
	{
		j = 0;
		while (j <= player->posy + 300)
		{
			if ((i + offseti) / ratio <= 0 || (j + offsetj) / ratio <= 0)
				my_mlx_pixel_put(i, j, img, black);
			else if (map[(int)((i + offseti) / ratio)]
					[(int)((j + offsetj) / ratio)] == '0')
				my_mlx_pixel_put(i, j, img, data->floor);
			else
				my_mlx_pixel_put(i, j, img, black);
			j++;
		}
		i++;
	}
	draw_circle(img, img->width / 2, img->height / 2, 100, red);
	draw_line(img, img->width / 2, img->height / 2, player->angle, 300, red);
}
