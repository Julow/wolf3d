/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:04:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/11 11:35:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"

# define WIDTH			800
# define HEIGHT			500

# define BLOCK_SIZE		64
# define CAMERA_ALT		32
# define VISION			60
# define PROJECTION		(WIDTH / 2) / tan(VISION / 2)

# define GROUND			0
# define WALL			1

# define B(b)			((b)->data[(b)->i])
# define BUFF(s,i,l)	((t_buff){(s), (i), (l)})

/*
** struct s_buff (t_buff) represent a buffer being parsed
** 'data' is not the original malloced pointer (can't be free)
** 'data' may not be NULL terminated
** macro B() return the current char
** macro BUFF() init a t_buff
*/
typedef struct	s_buff
{
	char			*data;
	int				i;
	int				length;
}				t_buff;

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

/*
** buff.c
*/
void			ft_parse(t_buff *buff, const char *parse);
int				ft_parseint(t_buff *buff);
double			ft_parsedouble(t_buff *buff);
void			ft_parsespace(t_buff *buff);

/*
** hooks.c
*/
int				expose_hook(void *param);
int				key_hook(int keycode, void *param);
int				loop_hook(void *param);

#endif
