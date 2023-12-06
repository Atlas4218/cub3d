/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:56:17 by rastie            #+#    #+#             */
/*   Updated: 2023/12/06 17:20:38 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	check_colors(t_data *data, char *file)
{
	if (!ft_strncmp(file, "F ", 2))
		data->floor = get_color(file + 1);
	if (!ft_strncmp(file, "C ", 2))
		data->ceiling = get_color(file + 1);
}

void	check_element(t_data *data, char *file)
{
	if (!ft_strncmp(file, "N ", 2))
	{
		if (data->wallno)
			free(data->wallno);
		data->wallno = get_img(file + 1, data);
	}
	if (!ft_strncmp(file, "S ", 2))
	{
		if (data->wallso)
			free(data->wallso);
		data->wallso = get_img(file + 1, data);
	}
	if (!ft_strncmp(file, "EA ", 3))
	{
		if (data->wallea)
			free(data->wallea);
		data->wallea = get_img(file + 2, data);
	}
	if (!ft_strncmp(file, "WE ", 3))
	{
		if (data->wallwe)
			free(data->wallwe);
		data->wallwe = get_img(file + 2, data);
	}
	check_colors(data, file);
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
		check_element(data, *file);
		file++;
	}
	while (*file && !**file)
		file++;
	if (!*file)
	{
		errno = 22;
		return (perror("Missing/Wrong element(s)\n"), closer(data), 0);
	}
	data->map = file;
	if (parse_map(file, data) || !data->nbplayer)
		return (1);
	return (0);
}
