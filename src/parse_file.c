/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:56:17 by rastie            #+#    #+#             */
/*   Updated: 2023/12/05 12:59:42 by gbonnard         ###   ########.fr       */
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

	line = map[i];
	j = 0;
	while (line[j])
	{
		if (!j && (line[j] != '1' && line[j] != ' '))
			return (perror("Map not closed\n"), 1);
		if (line[j] == 'N' || line[j] == 'E'
				|| line[j] == 'W' || line[j] == 'S')
		{
			if (data->nbplayer++)
				return (perror("Wrong number of player\n"), 1);
			init_player(data, j, i, line[j]);
			line[j] = '0';
		}
		else if (line[j] != ' ' && line[j] != '1' && line[j] != '0')
			return (perror("Unrecognised character\n"), 1);
		if (j && has_space_nearby(map, i, j) 
			&& !is_void(line[j]) && line[j] != '1')
			return (perror("Space wrongly placed\n"),1);
		j++;
	}
	return (0);
}

int	parse_first_last_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '1')
			return (perror("Wrong number of player\n"), 1);
		line ++;
	}
	return (0);
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

int	get_color(char *src)
{
 	char	**colors;
 	int	i;
 	int	color;

	while (*src == ' ')
		src++;
	colors = ft_simple_split(src, ',');
	i = 0;
	while(colors[i])
	{
		if (ft_strlen(colors[i]) > 3 || !is_all_digit(colors[i]))
		{
			errno = 22;
			return (perror("Wrong value\n"), clear_tab(colors), -1);
		}
		i++;
	}
	if (i != 3)
	{
		errno = 22;
		return (perror("The format is r,g,b\n"), clear_tab(colors), -1);
	}
	color = encode_rgb(ft_atoi(colors[0]),
			ft_atoi(colors[1]), ft_atoi(colors[2]));
	return (clear_tab(colors), color);
}


void	*get_img(char *filename, t_data *data)
{
	char	*ext;
	void	*result;

	ext = ft_strrchr(filename, '.');
	while (*filename == ' ')
		filename++;
	if (!ext || ft_strncmp(ext, ".xpm", 5))
	{
		errno = 22;
		return (perror("The file isn't a xpm file\n"), NULL);
	}
	result = mlx_xpm_file_to_image(data->mlx,
			filename, &(data->x), &data->y);
	if (!result)
		return (perror(filename), NULL);
	return (result);
}
int	parse_map(char	**map, t_data *data)
{
	int	i;

	i = 0;
	if (!fill_map(map))
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
	return (0);
}

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
	return (parse_map(file, data));
}
