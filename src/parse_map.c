/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:45:30 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/07 19:39:14 by rastie           ###   ########.fr       */
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

int	fill_map(char **map, t_data *data)
{
	int		i;
	char	*temp;
	char	*fill;

	data->lenmax = get_len_max(map);
	if (data->lenmax && data->lenmax < 3)
		return (0);
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) < (size_t)data->lenmax)
		{
			temp = map[i];
			fill = malloc(data->lenmax - ft_strlen(map[i]) + 1);
			if (!fill)
				return (perror("fill_map"), 0);
			ft_memset(fill, 32, data->lenmax - ft_strlen(map[i]));
			fill[data->lenmax - ft_strlen(map[i])] = 0;
			map[i] = ft_strjoin(temp, fill);
			free(temp);
			free(fill);
		}
	}
	return (1);
}

int	parse_room(char **map, int i, t_data *data)
{
	int		j;
	char	*line;

	line = map[i];
	j = 0;
	while (line[j])
	{
		if (!j && (line[j] != '1' && line[j] != ' '))
			return (ft_print_error("Map not closed", 22), 1);
		if (line[j] == 'N' || line[j] == 'E'
			|| line[j] == 'W' || line[j] == 'S')
		{
			if (data->nbplayer++)
				return (ft_print_error("Number of player", 22), 1);
			init_player(data, j, i, line[j]);
			line[j] = '0';
		}
		else if (line[j] != ' ' && line[j] != '1' && line[j] != '0')
			return (ft_print_error("Unrecognised character", 22), 1);
		if (j && has_space_nearby(map, i, j)
			&& !is_void(line[j]) && line[j] != '1')
			return (ft_print_error("Space wrongly placed", 22), 1);
		j++;
	}
	return (0);
}

int	parse_first_last_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '1')
			return (ft_print_error("Map not closed", 22), 1);
		line ++;
	}
	return (0);
}

int	parse_map(char	**map, t_data *data)
{
	int	i;

	i = 0;
	if (!fill_map(map, data))
		return (1);
	if (parse_first_last_line(map[i++]))
		return (1);
	while (map[i + 1])
	{
		if (parse_room(map, i, data))
			return (1);
		i++;
	}
	if (parse_first_last_line(map[i++]))
		return (1);
	data->nb_line_map = i;
	return (0);
}
