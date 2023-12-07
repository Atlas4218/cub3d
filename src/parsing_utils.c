/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:06:40 by rastie            #+#    #+#             */
/*   Updated: 2023/12/07 17:53:58 by rastie           ###   ########.fr       */
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

int	get_color(char *src)
{
	char	**colors;
	int		i;
	int		color;

	while (*src == ' ')
		src++;
	colors = ft_simple_split(src, ',');
	i = 0;
	while (colors[i])
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
			filename, &(data->x), &(data->y));
	if (!result)
		return (perror(filename), NULL);
	return (result);
}
