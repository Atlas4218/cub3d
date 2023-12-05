/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:33:57 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/05 16:22:51 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdlib.h>
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
	int		lineheight;
	int		line_length;
	int		drawstart;
	int		drawend;	
	int		bpp;
	int		size_l;
	int		endian;
	int		x;
	int		angle;
	float	perpwalldist;
	float	posx;
	float	posy;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;
	float	camerax;
	float	raydirx;
	float	raydiry;
	float	movespeed;
	float	rotspeed;
	float	sidedistx;
	float	sidedisty;
	float	deltadistx;
	float	deltadisty;
	void	*ray_ptr;
}	t_vector;

typedef struct s_circle
{
	int	x_center;
	int	y_center;
	int	radius;
}	t_circle;

typedef struct s_line
{
	int	x_origin;
	int	y_origin;
	int	length;
	int	angle;
}	t_line;

typedef struct s_data
{
	t_xpm		img;
	char		**file;
	char		**map;
	char		*mappath;
	int			x;
	int			y;
	t_img		*wallno;
	t_img		*wallso;
	t_img		*wallea;
	t_img		*wallwe;
	int			floor;
	int			ceiling;
	int			no;
	int			so;
	int			ea;
	int			we;
	int			nbplayer;
	int			forward;
	int			backward;
	int			strafeleft;
	int			straferight;
	int			rotateright;
	int			rotateleft;
	int			screen_width;
	int			screen_height;
	void		*mlx;
	void		*mlx_win;
	t_img		*img_map;
	t_vector	ray;
}	t_data;

int		main(int argc, char **argv);
void	clear_tab(char **tab);
int		init_data(t_data *data);
void	init_player(t_data *data, int x, int y, char c);
int		parse_file(char **file, t_data *data);
int		fill_map(char **map);
int		closer(t_data *data);
char	**get_file(char *filename);
int		get_angle(char c, t_data *data);
void	get_vector_dir(int angle, float *x, float *y);
int		raycasting(t_data *data);
void	steps_side_dist(t_data *data);
void	move_forward_backward(t_data *data);
void	strafe_right_left(t_data *data);
void	rotate_right(t_data *data);
void	rotate_left(t_data *data);
void	my_mlx_pixel_put(int x, int y, t_img *img, int color);
char	**ft_simple_split(char const *s, char c);
int		encode_rgb(int r, int g, int b);
int		inv_color(int original_color);
int		gest_minimap(t_data *data);
void	my_mlx_pixel_put(int x, int y, t_img *img, int color);
void	draw_circle(t_circle circle, t_img *img, int color);
void	draw_line(t_line line, t_img *img, int color);
int		is_void(char c);
int		has_space_nearby(char **map, int i, int j);
int		get_color(char *src);
void	*get_img(char *filename, t_data *data);
int		parse_map(char	**map, t_data *data);

#endif
