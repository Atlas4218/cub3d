/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:50:17 by rastie            #+#    #+#             */
/*   Updated: 2023/12/07 17:16:56 by gbonnard         ###   ########.fr       */
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
	int		i;
	int		x;
	int		y;
	double	dir_x;
	double	dir_y;

	dir_x = cos(line.angle * M_PI / 180);
	dir_y = -sin(line.angle * M_PI / 180);
	if (line.angle >= 180)
		dir_x *= -1;
	i = -1;
	while (++i <= line.length)
	{
		x = dir_x * i + line.x_origin;
		y = dir_y * i + line.y_origin;
		my_mlx_pixel_put(x, y, img, color);
	}
}
