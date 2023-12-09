/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:06:40 by rastie            #+#    #+#             */
/*   Updated: 2023/12/09 07:48:57 by roman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	is_void(char c)
{
	return (!c || c == ' ');
}

int	has_space_nearby(char **map, int i, int j)
{
	return (is_void(map[i][j + 1])
		|| is_void(map[i][j - 1])
		|| is_void(map[i + 1][j])
		|| is_void(map[i + 1][j + 1])
		|| is_void(map[i + 1][j - 1])
		|| is_void(map[i - 1][j])
		|| is_void(map[i - 1][j + 1])
		|| is_void(map[i - 1][j + 1]));
}

int	is_all_digit(char *str)
{
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

int	check_value(char *colors)
{
	return ((int)(unsigned char)ft_atoi(colors) != ft_atoi(colors)
		|| (int)(unsigned char)ft_atoi(colors) != ft_atoi(colors)
		|| (int)(unsigned char)ft_atoi(colors) != ft_atoi(colors));
}
