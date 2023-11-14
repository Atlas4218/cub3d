/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:58:59 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/14 18:33:05 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	clear_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	closer(t_data *data)
{
	if (data->map)
		clear_map(data->map);
	free(data->mlx);
	exit(0);
	return (5);
}

int	handle_keyevent(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		closer(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		errno = 22;
		return (perror("Erreur"), errno);
	}
	data.mappath = argv[1];
	if (init_data(&data))
		return (closer(&data));
}
