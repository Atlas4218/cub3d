/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:24:51 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/04 11:42:57 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	get_vector_dir(int angle, double *x, double *y)
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

