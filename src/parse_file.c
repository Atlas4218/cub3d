/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:56:17 by rastie            #+#    #+#             */
/*   Updated: 2023/12/08 16:26:14 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_colors(t_data *data, char *file)
{
	if (!ft_strncmp(file, "F ", 2) && data->floor < 0)
	{
		data->floor = get_color(file + 1);
		if (data->floor < 0)
			return (1);
		return (0);
	}
	if (!ft_strncmp(file, "C ", 2) && data->ceiling < 0)
	{
		data->ceiling = get_color(file + 1);
		if (data->ceiling < 0)
			return (1);
		return (0);
	}
	return (ft_print_error("Duplicate color key", 22), 1);
}

int	check_wall(t_data *data, char *file)
{
	if (!ft_strncmp(file, "NO ", 3) && !data->wallno)
	{
		data->wallno = get_img(file + 2, data);
		return (!data->wallno);
	}
	else if (!ft_strncmp(file, "SO ", 3) && !data->wallso)
	{
		data->wallso = get_img(file + 2, data);
		return (!data->wallso);
	}
	else if (!ft_strncmp(file, "EA ", 3) && !data->wallea)
	{
		data->wallea = get_img(file + 2, data);
		return (!data->wallea);
	}
	else if (!ft_strncmp(file, "WE ", 3) && !data->wallwe)
	{
		data->wallwe = get_img(file + 2, data);
		return (!data->wallwe);
	}
	return (ft_print_error("Duplicate img key", 22), 1);
}

int	check_element(t_data *data, char *file)
{
	if (!*file)
		return (0);
	else if (!ft_strncmp(file, "NO ", 3) || !ft_strncmp(file, "SO ", 3)
		|| !ft_strncmp(file, "EA ", 3) || !ft_strncmp(file, "WE ", 3))
		return (check_wall(data, file));
	else if (!ft_strncmp(file, "F ", 2) || !ft_strncmp(file, "C ", 2))
		return (check_colors(data, file));
	else if (*file)
		return (ft_print_error("Incorrect key", 22), 1);
	return (0);
}


int	parse_file(char **file, t_data *data)
{
	if (!file || !data)
		return (0);
	data->floor = -1;
	data->ceiling = -1;
	while ((!data->wallno || !data->wallso || !data->wallea || !data->wallwe
			|| data->floor < 0 || data->ceiling < 0
		) && *file)
	{
		if (check_element(data, *file))
			return (closer(data), 0);
		file++;
	}
	while (*file && !**file)
		file++;
	if (!*file)
		return (ft_print_error("Missing map", 22),
			closer(data), 0);
	data->map = file;
	if (parse_map(file, data))
		return (1);
	if (!data->nbplayer)
		return (ft_print_error("Wrong number of player", 22),
			closer(data), 0);
	return (0);
}
