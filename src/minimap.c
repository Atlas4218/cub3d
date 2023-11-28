/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:16:15 by rastie            #+#    #+#             */
/*   Updated: 2023/11/28 19:07:28 by rastie           ###   ########.fr       */
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

void	draw_line(t_img *img, int x, int y, int angle, int len, int color)
{
	
}

void	draw_map(t_data *data, t_img *img)
{
	t_player	*player;

	player = data->player;
	// recuperation des coos du joueur
	int	x = player->x;
	int	y = player->y;
	int	i = 0;
	int	j;
	while (i <= x + 300)
	{
		j = 0;
		while (j <= y + 300)
		{
			if ((i + offseti) / ratio <= 0 || (j + offsetj) / ratio <= 0)
				my_mlx_pixel_put(i, j, img, black);
			else if (map[(i + offseti) / ratio][(j + offsetj) / ratio] == '0')
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
