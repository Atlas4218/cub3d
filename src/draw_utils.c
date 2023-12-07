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
	int dx;
	int dy;
	int err;
	int sx;
	int sy;

	dx = abs(line.end_x - line.x_origin);
	dy = abs(line.end_y - line.y_origin);
	if (line.x_origin < line.end_x) 
		sx = 1;
	else 
		sx = -1;
	if (line.y_origin < line.end_y) 
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	while (line.x_origin != line.end_x || line.y_origin != line.end_y)
	{
		my_mlx_pixel_put(line.x_origin, line.y_origin, img, color);

		if ((err << 1) > -dy)
		{
			err -= dy;
			line.x_origin += sx;
		}
		if ((err << 1) < dx) 
		{
			err += dx;
			line.y_origin += sy;
		}
	}
}

void	draw_line(t_line line, t_img *img, int color)
{
	int	end_x;
	int	end_y;
	int	i;
	int	j;

	i = line.x_origin;
	j = line.y_origin;
	end_x = line.length * cos(line.angle * M_PI / 180) + i;
	end_y = line.length * sin(line.angle * M_PI / 180) + j;

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

