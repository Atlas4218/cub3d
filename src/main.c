/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:58:59 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/29 11:38:30 by gbonnard         ###   ########.fr       */
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

void	cub(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 800, 600, "Cub3D");
	data->ray.ray_ptr = mlx_new_image(data->mlx, 800, 600);
	data->ray.data_addr = (int *)mlx_get_data_addr(data->ray.ray_ptr,
			&data->ray.bpp, &data->ray.size_l, &data->ray.endian);
	mlx_loop_hook(data->mlx, raycasting, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->ray.ray_ptr, 0, 0);
	mlx_loop(data->mlx);
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
	cub(&data);
	return (0);
}
