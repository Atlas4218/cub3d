/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:56:17 by rastie            #+#    #+#             */
/*   Updated: 2023/11/25 18:49:55 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	has_space_nearby(char *line, int i)
{

}

int	parse_room(char *line, t_data *data)
{
	int	i;
	
	i = 0;
	while (line[i])
	{
		if (!is_valid(line[i]))
			return (1);
		if (is_player(line[i]))
		{
			if (data->nbplayer)
				return (1);
			vars->player->angle = get_angle(line[i]);
			vars->nbplayer++;
		}
		if (has_space_nearby(line, i) 
			&& !is_void(line[i]) && line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	parse_first_last_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '1')
			return (1);
		line ++;
	}
	return (0);
}

int	parse_map(char	**map, t_data *data)
{
	if (parse_first_last_line(*map))
		return (0);
	while (map + 1)
	{
		if (parse_room(*map))
			return (0);
		map++;
	}
	if (parse_first_last_line(*map))
		return (0);
}

int	parse_file(char **file, t_data *data)
{
	if (!file || !data)
		return (0);
	while ((!data->wallno || !data->wallso || !data->wallea || !data->wallwe
		|| !data->floor || !data->ceiling) && *file)
	{
		if (!ft_strncmp(*file, "N", 2))
			data->wallno = get_img((*file) + 1);
		if (!ft_strncmp(*file, "S", 2))
			data->wallso = get_img((*file) + 1);
		if (!ft_strncmp(*file, "EA", 3))
			data->wallea = get_img((*file) + 2);
		if (!ft_strncmp(*file, "WE", 3))
			data->wallwe = get_img((*file) + 2);
		if (!ft_strncmp(*file, "F", 2))
			data->floor = get_img((*file) + 1);
		if (!ft_strncmp(*file, "C", 2))
			data->ceiling = get_img((*file) + 1);
		file++;
	}
	while (*file && !**file)
		file++
	if (!*file)
		return (closer(data), 0);	//il manque un element
	return (parse_map(file, data))
}

