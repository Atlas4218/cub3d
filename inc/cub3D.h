/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:33:57 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/14 14:43:31 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUBE3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/Xutil.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_xpm
{
	int		width;
	int		height;
}	t_xpm;

typedef struct s_vector
{
	int		x;
	int		y;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;	
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	movespeed;
	double	rotspeed;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;

}	t_vector;

typedef struct s_data
{
	t_xpm		img;
	char		**map;
	char		*mappath;
	int			x;
	int			y;
	t_img		*wallno;
	t_img		*wallso;
	t_img		*wallea;
	t_img		*wallwe;
	t_img		*floor;
	t_img		*celling;
	int			forward;
	int			backward;
	int			strafeleft;
	int			straferight;
	int			rotateright;
	int			rotateleft;
	int			swidth;
	int			sheight;
	void		*mlx;
	void		*mlx_win;
	t_vector	ray;
}	t_data;

int		main(int argc, char **argv);
int		init_data(t_data *data);
int		parse_map(char **map, t_data *data);
int		closer(t_data *data);
char	**get_map(char *filename);

#endif