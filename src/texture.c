/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:16:25 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/06 12:39:17 by rastie           ###   ########.fr       */
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
	data->texture[0].width = data->wallno->width;
	data->texture[0].height = data->wallno->height;
	data->texture[1].img = data->wallso;
	data->texture[1].width = data->wallso->width;
	data->texture[1].height = data->wallso->height;
	data->texture[2].img = data->wallea;
	data->texture[2].width = data->wallea->width;
	data->texture[2].height = data->wallea->height;
	data->texture[3].img = data->wallwe;
	data->texture[3].width = data->wallwe->width;
	data->texture[3].height = data->wallwe->height;
	get_tex_addr(data);
	return (0);
}
