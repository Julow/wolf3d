/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:04:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 08:54:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"

# define WIDTH			1250
# define HEIGHT			900

# define BLOCK_SIZE		100
# define CAMERA_ALT		32
# define VISION			1.1170107212
# define PROJECTION		(WIDTH / 2) / tan(VISION / 2)

# define SPEED			40

# define GROUND			0
# define WALL			1

# define COLOR_NORTH	C(0xFFAA0000)
# define COLOR_EST		C(0xFF888800)
# define COLOR_SUD		C(0xFF00AA22)
# define COLOR_WEST		C(0xFF3099BB)

# define KEY_ESC		65307
# define KEY_LEFT		65361
# define KEY_UP			65362
# define KEY_RIGHT		65363
# define KEY_DOWN		65364

# define LPT(x,y)		((t_lpt){(x), (y)})

typedef struct	s_lpt
{
	double			x;
	double			y;
}				t_lpt;

typedef struct	s_map
{
	int				**data;
	int				width;
	int				height;
	t_pt			spawn;
	double			spawn_dir;
}				t_map;

typedef struct	s_player
{
	t_pt			pos;
	double			dir;
}				t_player;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	t_player		player;
	t_map			map;
	t_image			img;
	t_bool			redraw;
}				t_env;

/*
** game.c
*/
void			init_game(t_env *env);
void			draw_gui(t_env *env);

/*
** ray.c
*/
void			draw_map(t_env *env);

/*
** map.c
*/
int				map_get(t_env *map, t_pt pt);
void			map_ini(t_map *map, const char *file);

/*
** env.c
*/
t_env			*env_new(void *mlx);
void			env_start(t_env *env);
void			env_exit(t_env *env);

/*
** utils.c
*/
void			error(char *error);
double			ft_dist(t_pt p1, t_pt p2);
t_pt			ft_nearest(t_pt pos, t_pt p1, t_pt p2);
void			ft_drawvert(t_image *img, t_pt pt, int height, t_color color);

/*
** hooks.c
*/
int				expose_hook(void *param);
int				key_hook(int keycode, void *param);
int				loop_hook(void *param);

#endif
