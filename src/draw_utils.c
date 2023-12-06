/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:50:17 by rastie            #+#    #+#             */
/*   Updated: 2023/12/06 16:39:48 by gbonnard         ###   ########.fr       */
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
	int	y;

	i = line.x_origin;
	y = line.y_origin;
	end_x = line.length * cos(line.angle * M_PI / 180) + i;
	if (line.angle == 270)
			while (y >= line.y_origin - line.length)
				my_mlx_pixel_put(i, y--, img, color);
	else if (line.angle == 90)
			while (y >= line.y_origin + line.length)
				my_mlx_pixel_put(i, y++, img, color);
	else if (line.angle > 90 && line.angle < 270)
	{
		while (i >= end_x)
		{
			y = tan(line.angle * M_PI / 180) * (i - line.x_origin)
				+ line.y_origin;
			my_mlx_pixel_put(i--, y, img, color);
		}
	}
	else
	{
		while (i <= end_x)
		{
			y = tan(line.angle * M_PI / 180) * (i - line.x_origin)
				+ line.y_origin;
			my_mlx_pixel_put(i++, y, img, color);
		}
	}
}


/*
 end_x = length * cos(angle * M_PI / 180)


 si l'angle est 90 ou 270
 	90
		put_pixel
	270
		put_pixel
	
sinon si l'angle est compris entre 90 t 270 exclus
 	tant que x >= end_x
		calcul y
		put_pixel
		i--
sinon
	tant que x <= end_x
		calcul y
		put_pixel
		i++

calcul de y
tan(angle) = sin/cos = Oppose sur ajacent
l'oppose = y = sin(angle)
tan(angle) * x
*/
   	
