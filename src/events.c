/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:51:26 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/06 16:51:44 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 'a')
		data->strafeleft = 1;
	else if (keycode == XK_Left)
		data->rotateright = 1;
	else if (keycode == 'w' || keycode == XK_Up)
		data->forward = 1;
	else if (keycode == 's' || keycode == XK_Down)
		data->backward = 1;
	else if (keycode == 'd')
		data->straferight = 1;
	else if (keycode == XK_Right)
		data->rotateleft = 1;
	else if (keycode == XK_Escape)
		closer(data);
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == 'a')
		data->strafeleft = 0;
	else if (keycode == XK_Left)
		data->rotateright = 0;
	else if (keycode == 'w' || keycode == XK_Up)
		data->forward = 0;
	else if (keycode == 's' || keycode == XK_Down)
		data->backward = 0;
	else if (keycode == 'd')
		data->straferight = 0;
	else if (keycode == XK_Right)
		data->rotateleft = 0;
	return (0);
}