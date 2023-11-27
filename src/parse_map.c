/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:45:30 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/21 19:21:51 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_wall(char **map)
{
	return (0);
}


/* corriger la carte, remplir de mur pour avoir une carte rectangulaire
   puis parsing
   */
int	get_len_max(char **max)
{
	int	lenmax;

	lenmax = 2;
	while (*map)
	{
		if (!ft_strlen(*map))
			return (perror("Empty line in map\n"), 0)
		if (ft_strlen(*map) > lenmax)
			lenmax = ft_strlen(*map);
		map++;
	}
	return (lenmax);
}

int	fill_map(char **map)
{
	int	lenmax;
	int	i;
	char	*temp;
	char	*fill;
	
	lenmax = get_len_max(map);
	if (lenmax && lenmax < 3)
		return (0);	//error map trop petite
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) < lenmax)
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


/* premiere et derniere lignes, uniquement des 1 ou des espaces
   sinon 1 ou espace obligatoire autour d'un espace ou fin de ligne */

int	parse_map(char **map, t_data *data)
{
	if (!data || !map || !*map)
		return (6);
	if (check_wall(data->map))
		return (closer(data));
	return (0);
}
