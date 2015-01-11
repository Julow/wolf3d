/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:38:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/11 17:07:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static t_pt		cast_x(t_env *env, double dir)
{
	double			x;
	int				y;
	double			delta;
	int				delta_y;

	delta = BLOCK_SIZE / tan(dir);
	x = env->player.pos.x;
	y = env->player.pos.y / BLOCK_SIZE * BLOCK_SIZE;
	delta_y = (sin(dir) < 0) ? -BLOCK_SIZE : BLOCK_SIZE;
	while (1)
	{
		if (map_get(env, PT((int)x, y)) != GROUND)
			break ;
		y += delta_y;
		x += delta;
	}
	return (PT((int)x, y));
}

static t_pt		cast_y(t_env *env, double dir)
{
	int				x;
	double			y;
	double			delta;
	int				delta_x;

	delta = BLOCK_SIZE / tan(dir);
	x = env->player.pos.x / BLOCK_SIZE * BLOCK_SIZE;
	y = env->player.pos.y;
	delta_x = (sin(dir) < 0) ? -BLOCK_SIZE : BLOCK_SIZE;
	while (1)
	{
		if (map_get(env, PT(x, (int)y)) != GROUND)
			break ;
		x += delta_x;
		y += delta;
	}
	return (PT(x, (int)y));
}

static void		draw_wall(t_env *env, t_pt a, t_pt b, int x)
{
	const t_pt		pt = ft_nearest(env->player.pos, a, b);
	int				height;
	int				tmp;

	height = (PROJECTION * BLOCK_SIZE) / ft_dist(pt, env->player.pos);
	tmp = (HEIGHT - height) / 2;
	ft_drawvert(&(env->img), PT(x, tmp), HEIGHT - tmp - tmp, C(0xFFFF8800));
	ft_drawvert(&(env->img), PT(x, HEIGHT - tmp), tmp, C(0xFF0f1d02));
}

void			draw_map(t_env *env)
{
	double			delta;
	double			dir;
	int				x;

	delta = VISION / WIDTH;
	dir = -(VISION / 2);
	x = 0;
	while (x < WIDTH)
	{
		draw_wall(env, cast_x(env, dir + env->player.dir),
			cast_y(env, dir + env->player.dir), x);
		x++;
		dir += delta;
	}
}
