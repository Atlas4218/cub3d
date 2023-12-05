/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:24:51 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/05 13:30:28 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	get_vector_dir(int angle, float *x, float *y)
{
	*x = cos(angle * M_PI / 180.0);
	*y = sin(angle * M_PI / 180.0);
}

int	get_angle(char c, t_data *data)
{
	if (c == 'E')
		return ((data->ray.planey = 0.66), 0);
	if (c == 'S')
		return ((data->ray.planex = -0.66), 90);
	if (c == 'W')
		return ((data->ray.planey = -0.66), 180);
	return ((data->ray.planex = 0.66), 270);
}

int	encode_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	decode_rgb(int color, int *r, int *g, int *b)
{
	*r = (color >> 16) & 0xFF;
	*g = (color >> 8) & 0xFF;
	*b = color & 0xFF;
}

int	inv_color(int original_color)
{
	int	r;
	int	g;
	int	b;

	decode_rgb(original_color, &r, &g, &b);
	return (encode_rgb(255 - r, 255 - g, 255 - b));
}
