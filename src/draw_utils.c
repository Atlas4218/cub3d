/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:50:17 by rastie            #+#    #+#             */
/*   Updated: 2023/12/07 13:12:21 by gbonnard         ###   ########.fr       */
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

void	bresenham(t_img *img, t_line line, int color)
{   
	int dx = line.end_x - line.x_origin;
	int dy = line.end_y - line.y_origin;
	int slope = 2 * dy;
	int error = -dx;
	int errorInc = -2 * dx;

	while (line.x_origin <= line.end_x)
	{
		my_mlx_pixel_put(line.x_origin, line.y_origin, img, color);
		error += slope;
		if (error >= 0)
		{
			line.y_origin++;
			error += errorInc;
		}
		line.x_origin++;
	}
}

void	draw_line(t_line line, t_img *img, int color)
{
	line.end_x = line.length * cos(line.angle * M_PI / 180) + line.x_origin;
	line.end_y = line.length * -sin(line.angle * M_PI / 180) + line.y_origin;
	bresenham(img, line, color);
}
