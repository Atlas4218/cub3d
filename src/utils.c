/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:24:51 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/29 17:08:47 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_vector_dir(int angle, double &x, double &y)
{
		*x = cos(angle);
		*y = sin(angle);
}
i
int	get_angle(char c)
{
	if (c == 'E')
		return (0);
	if (c == 'N')
		return (90);
	if (c == 'W')
		return (180);
	return (270);
}

