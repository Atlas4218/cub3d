/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:24:51 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/02 12:51:34 by roman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	get_vector_dir(int angle, float *x, float *y)
{
		*x = cos(angle * M_PI / 180.0);
		*y = sin(angle * M_PI / 180.0);
}

int	get_angle(char c)
{
	if (c == 'E')
		return (0);
	else if (c == 'N')
		return (90);
	else if (c == 'W')
		return (180);
	return (270);
}

