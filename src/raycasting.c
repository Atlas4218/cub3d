/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:33:58 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/14 18:39:36 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	raycasting(t_data *data)
{
	while (data->x < data->screen_width)
	{
		data->ray.camerax = 2 * data->x / data->screen_width - 1;
		data->ray.raydirx = data->ray.dirx
			+ data->ray.planex * data->ray.camerax;
		data->ray.raydiry = data->ray.diry
			+ data->ray.planey * data->ray.camerax;
	}
}
