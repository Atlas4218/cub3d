/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:50:17 by rastie            #+#    #+#             */
/*   Updated: 2023/12/05 15:10:56 by rastie           ###   ########.fr       */
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

void	draw_circle(t_circle circle, t_img *img, int color)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = circle.x_center;
	y = circle.y_center;
	i = circle.radius - x;
	while (i <= x + circle.radius)
	{
		j = circle.radius - y;
		while (j <= y + circle.radius)
		{
			if ((pow(i - x, 2) + pow(j - y, 2)) <= pow(circle.radius, 2))
				my_mlx_pixel_put(i, j, img, color);
			j++;
		}
		i++;
	}
}

void	draw_line(t_line line, t_img *img, int color)
{
	int	end_x;
	int	i;
	int	j;

	end_x = line.x_origin + line.length * cos(line.angle * M_PI / 180);
	i = line.x_origin;
	j = line.y_origin;
	if (line.angle != 90.0 && line.angle != 270.0)
	{
		while (i <= end_x)
		{
			j = line.y_origin + (i - line.x_origin)
				* tan(line.angle * M_PI / 180);
			my_mlx_pixel_put(i++, j, img, color);
		}
	}
	else
		while (j >= line.y_origin - line.length)
			my_mlx_pixel_put(i, j--, img, color);
}
