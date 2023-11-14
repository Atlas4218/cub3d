/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:45:30 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/14 18:32:48 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_wall(char **map)
{
	return (0);
}

int	parse_map(char **map, t_data *data)
{
	if (!data || !map || !*map)
		return (6);
	if (check_wall(data->map))
		return (closer(data));
	return (0);
}
