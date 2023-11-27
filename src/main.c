/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:58:59 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/27 17:53:48 by gbonnard         ###   ########.fr       */
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
	free(data->mlx_ptr);
	exit(0);
	return (5);
}

int	handle_keyevent(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		closer(data);
	return (0);
}
void	init_data(t_data *data)
{
	int	map_height = 10;
	int map_width = 12;
	data->ray.posx = 3;
	data->ray.posy = 3;
	data->ray.dirx = 0;
	data->ray.diry = 0;
	data->ray.planex = 0;
	data->ray.planey = 0;
	data->ray.mapx = (int)data->ray.posx;
	data->ray.mapy = (int)data->ray.posy;
	data->screen_width = 800;
	data->screen_height = 600;
	data->map = (char **)malloc(sizeof(char *) * map_height);
	char map_data[10][12] = {
		"1111111111",
		"1000000001",
		"1000000001",
		"1011111101",
		"1011111101",
		"1001110001",
		"1100000111",
		"1110011111",
		"1000111111",
		"1111111111",
	};
	for (int i = 0; i < map_height; i++){
		data->map[i] = (char *)malloc(sizeof(char) * (map_width + 1));
		strcpy(data->map[i], map_data[i]);
	}
}

void	cub3D(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, 800, 600, "Cub3D");
	data->ray.ray_ptr = mlx_new_image(data->mlx_ptr, 800, 600);
	data->ray.data_addr = (int *)mlx_get_data_addr(data->ray.ray_ptr,
			&data->ray.bpp, &data->ray.size_l, &data->ray.endian);
	mlx_loop_hook(data->mlx_ptr, raycasting, data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->ray.ray_ptr, 0, 0);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;

		(void)argc;
		(void)argv;
		// if (argc != 2)
		// {
		// 	errno = 22;
		// 	return (perror("Erreur"), errno);
		// }
		// data.mappath = argv[1];
		// if (init_data(&data))
		// 	return (closer(&data));
	init_data(&data);
	cub3D(&data);
	return (0);
}
