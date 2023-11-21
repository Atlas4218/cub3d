/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:33:58 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/21 18:40:47 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
*	Initialisation et protection de DeltaDist (distance entre deux cote x ou y d'un carre en fontion du joueur)
*/

void	deltadist_init(t_data *data)
{
	if (data->ray.raydiry == 0)
		data->ray.deltadistx = 0;
	else if (data->ray.raydirx == 0)
		data->ray.deltadistx = 1;
	else
		data->ray.deltadistx = sqrt(1 + (data->ray.raydiry * data->ray.raydiry)
				/ (data->ray.raydirx * data->ray.raydirx));
	if (data->ray.raydiry == 0)
		data->ray.deltadisty = 0;
	else if (data->ray.raydirx == 0)
		data->ray.deltadisty = 1;
	else
		data->ray.deltadisty = sqrt(1 + (data->ray.raydirx * data->ray.raydirx)
				/ (data->ray.raydiry * data->ray.raydiry));
}

/*
*	fonction global d'ou part les different calcul de raycasting pour etre gerer par mlx_loop_hook
*/
int	raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->screen_width)
	{
		data->ray.camerax = 2 * x / (double)data->screen_width - 1;
		data->ray.raydirx = data->ray.dirx
			+ data->ray.planex * data->ray.camerax;
		data->ray.raydiry = data->ray.diry
			+ data->ray.planey * data->ray.camerax;
		deltadist_init(data);
		steps_side_dist(data);
		x++;
	}
	move_forward_backward(data);
	strafe_right_left(data);
	rotate_right(data);
	rotate_left(data);
	return (0);
}
