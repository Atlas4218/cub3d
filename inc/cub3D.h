/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:33:57 by gbonnard          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/27 17:39:26 by gbonnard         ###   ########.fr       */
=======
/*   Updated: 2023/11/29 11:56:01 by gbonnard         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
	int		*data_addr;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		perpwalldist;
	int		lineheight;
	int		line_length;
	int		drawstart;
	int		drawend;	
	int		bpp;
	int		size_l;
	int		endian;
	int		x;
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
	void	*ray_ptr;
<<<<<<< HEAD
=======

	int		angle;
>>>>>>> main

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
<<<<<<< HEAD
	t_img		*celling;
=======
	t_img		*ceiling;
>>>>>>> main

	int			no;
	int			so;
	int			ea;
	int			we;

<<<<<<< HEAD

=======
>>>>>>> main
	int			forward;
	int			backward;
	int			strafeleft;
	int			straferight;
	int			rotateright;
	int			rotateleft;
	int			screen_width;
	int			screen_height;
	void		*mlx_ptr;
	void		*mlx_win;
	t_vector	ray;
}	t_data;

int		main(int argc, char **argv);
void		init_data(t_data *data);
int		parse_map(char **map, t_data *data);
int		fill_map(char **map);
int		closer(t_data *data);
char	**get_map(char *filename);
int		raycasting(t_data *data);
void	steps_side_dist(t_data *data);
void	move_forward_backward(t_data *data);
void	strafe_right_left(t_data *data);
void	rotate_right(t_data *data);
void	rotate_left(t_data *data);

#endif
