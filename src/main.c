/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:58:59 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/06 16:51:44 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	clear_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	closer(t_data *data)
{
	if (data->file)
		clear_tab(data->file);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->wallno)
		mlx_destroy_image(data->mlx, data->wallno);
	if (data->wallso)
		mlx_destroy_image(data->mlx, data->wallso);
	if (data->wallea)
		mlx_destroy_image(data->mlx, data->wallea);
	if (data->wallwe)
		mlx_destroy_image(data->mlx, data->wallwe);
	if (data->img_map)
		mlx_destroy_image(data->mlx, data->img_map);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
	return (5);
}

void	cub(t_data *data)
{
	init_wall(data);
	data->ray.ray_ptr = mlx_new_image(data->mlx, 800, 600);
	data->ray.data_addr = (int *)mlx_get_data_addr(data->ray.ray_ptr,
			&data->ray.bpp, &data->ray.size_l, &data->ray.endian);
	data->mlx_win = mlx_new_window(data->mlx, 800, 600, "Cub3D");
	data->ray.ray_ptr2 = mlx_new_image(data->mlx, 800, 600);
	data->ray.data_addr2 = (int *)mlx_get_data_addr(data->ray.ray_ptr2,
			&data->ray.bpp, &data->ray.size_l, &data->ray.endian);
	mlx_hook(data->mlx_win, 33, 0L, closer, data);
	mlx_hook(data->mlx_win, 02, 1L << 0, handle_keypress, data);
	mlx_loop_hook(data->mlx, raycasting, data);
	mlx_hook(data->mlx_win, 03, 1L << 1, handle_keyrelease, data);
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
	ft_bzero (&data, sizeof(data));
	data.mappath = argv[1];
	if (init_data(&data))
		return (closer(&data));
	cub(&data);	
	minimap(&data);
	return (0);
}
