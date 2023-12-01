/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:45:30 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/01 00:48:43 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/* corriger la carte, remplir de mur pour avoir une carte rectangulaire
   puis parsing
   */
int	get_len_max(char **map)
{
	int	lenmax;

	lenmax = 2;
	while (*map)
	{
		if (ft_strlen(*map) > (size_t)lenmax)
			lenmax = ft_strlen(*map);
		map++;
	}
	return (lenmax);
}

int	fill_map(char **map)
{
	int		lenmax;
	int		i;
	char	*temp;
	char	*fill;

	lenmax = get_len_max(map);
	if (lenmax && lenmax < 3)
		return (0);	//error map trop petite
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) < (size_t)lenmax)
		{
			temp = map[i];
			fill = malloc(lenmax - ft_strlen(map[i]));
			if (!fill)
				return (0);	//error malloc;
			ft_memset(fill, 32, lenmax - ft_strlen(map[i]));
			map[i] = ft_strjoin(temp, fill);
			free(temp);
			free(fill);
		}
		i++;
	}
	return (1);
}
