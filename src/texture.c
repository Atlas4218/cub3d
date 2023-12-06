/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:16:25 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/06 10:27:59 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	get_tex_addr(t_data *data)
{
	data->texture[0].addr = (int *)mlx_get_data_addr(data->texture[0].img,
			&data->texture[0].bpp, &data->texture[0].size_l,
			&data->texture[0].endian);
	data->texture[1].addr = (int *)mlx_get_data_addr(data->texture[1].img,
			&data->texture[1].bpp, &data->texture[1].size_l,
			&data->texture[1].endian);
	data->texture[2].addr = (int *)mlx_get_data_addr(data->texture[2].img,
			&data->texture[2].bpp, &data->texture[2].size_l,
			&data->texture[2].endian);
	data->texture[3].addr = (int *)mlx_get_data_addr(data->texture[3].img,
			&data->texture[3].bpp, &data->texture[3].size_l,
			&data->texture[3].endian);
}

int	init_wall(t_data *data)
{
	data->texture[0].img = data->wallno;
	data->texture[1].img = data->wallso;
	data->texture[2].img = data->wallea;
	data->texture[3].img = data->wallwe;
	get_tex_addr(data);
	return (0);
}
