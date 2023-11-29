/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:56:17 by rastie            #+#    #+#             */
/*   Updated: 2023/11/29 14:14:13 by rastie           ###   ########.fr       */
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

int	parse_room(char **map, int i, t_data *data)
{
	int		j;
	char	*line;

	(void)data;
	line = map[i];
	j = 0;
	while (line[j])
	{
		if (!j && (line[j] != '1' || line[j] != ' ')
				return (1);
		/*if (line[j] == 'N' || line[j] == 'E'
			|| line[i] == 'W' || line[i] == 'S')
		{
			if (data->nbplayer)
				return (1);
			vars->player->angle = get_angle(line[j]);
			vars->nbplayer++;
		}*/
		if (line[j] != ' ' && line[i] != '1' && line[i] != '0'
			|| line[j] == 'N' || line[j] == 'E'
			|| line[i] == 'W' || line[i] == 'S')
			return (1);
		if (has_space_nearby(map, i, j) 
			&& !is_void(line[j]) && line[j] != '1')
			return (1);
		j++;
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

void	*get_img(char *filename, t_data *data)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext)
		return (NULL);
	while (*filename == ' ')
		filename++;
	if (ft_strncmp(ext, ".xpm", 5))
		return (NULL);
	return (mlx_xpm_file_to_image(data->mlx, filename, &(data->x), &data->y));
}
int	parse_map(char	**map, t_data *data)
{
	int	i;

	i = 0;
	if (!fill_map(map))
		return (1);
	if (parse_first_last_line(map[i++]))
		return (1);
	while (map[i])
	{
		if (parse_room(map, i, data))
			return (1);
	}
	if (parse_first_last_line(map[i]))
		return (1);
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
			data->wallno = get_img((*file) + 1, data);
		if (!ft_strncmp(*file, "S", 2))
			data->wallso = get_img((*file) + 1, data);
		if (!ft_strncmp(*file, "EA", 3))
			data->wallea = get_img((*file) + 2, data);
		if (!ft_strncmp(*file, "WE", 3))
			data->wallwe = get_img((*file) + 2, data);
		if (!ft_strncmp(*file, "F", 2))
			data->floor = get_img((*file) + 1, data);
		if (!ft_strncmp(*file, "C", 2))
			data->ceiling = get_img((*file) + 1, data);
		file++;
	}
	while (*file && !**file)
		file++;
	if (!*file)
		return (closer(data), 0);	//il manque un element
	return (parse_map(file, data));
}