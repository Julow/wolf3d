/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:38:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/18 17:11:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static t_color	wall_color(t_pt p1, t_pt p2)
{
	p1.x -= p2.x;
	p1.y -= p2.y;
	if (p1.x == 0 && p1.y > 0)
		return (COLOR_EST);
	if (p1.x == 0 && p1.y < 0)
		return (COLOR_WEST);
	if (p1.x > 0 && p1.y == 0)
		return (COLOR_NORTH);
	if (p1.x < 0 && p1.y == 0)
		return (COLOR_SUD);
	return (COLOR_CORNER);
}

static void		cast(t_env *env, double dir, int x)
{
	t_dpt			delta;
	t_dpt			pos;
	int				wall;
	t_pt			last;
	t_pt			tmp;

	pos = DPT(env->player.pos.x, env->player.pos.y);
	last = env->player.pos;
	delta = DPT(cos(dir), sin(dir));
	while (1)
	{
		tmp = PT((int)pos.x, (int)pos.y);
		if (map_get(env, tmp) != MAP_GROUND)
			break ;
		last = tmp;
		pos.x += delta.x;
		pos.y += delta.y;
	}
	wall = (HEIGHT - ((PROJECTION * env->map.block)
		/ ft_dist(tmp, env->player.pos))) / 2;
	ft_drawvert(&(env->img), PT(x, 0), wall, COLOR_SKY);
	ft_drawvert(&(env->img), PT(x, wall), HEIGHT - wall - wall,
		wall_color(round_block(env, last), round_block(env, tmp)));
	ft_drawvert(&(env->img), PT(x, HEIGHT - wall), wall, COLOR_GROUND);
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
		cast(env, dir + env->player.dir, x);
		x++;
		dir += delta;
	}
}
/*
static t_pt		cast_y(t_env *env, double dir)
{
	t_pt			delta;
	t_pt			pt;

	delta.x = (cos(dir) > 0) ? env->map.block : -env->map.block;
	delta.y = env->map.block * tan(dir);
	pt.x = (env->player.pos.x) / env->map.block * env->map.block + delta.x;
	pt.y = (env->player.pos.y - pt.x) * tan(dir) + env->player.pos.y;
	while (1)
	{
		if (map_get(env, pt) != MAP_GROUND)
			break ;
		pt.x += delta.x;
		pt.y += delta.y;
	}
	return (pt);
}

static t_pt		cast_x(t_env *env, double dir)
{
	t_pt			delta;
	t_pt			pt;

	delta.x = env->map.block / tan(dir);
	delta.y = (sin(dir) > 0) ? env->map.block : -env->map.block;
	pt.y = (env->player.pos.y) / env->map.block * env->map.block + delta.y;
	pt.x = (env->player.pos.y - pt.y) / tan(dir) + env->player.pos.x;
	while (1)
	{
		if (map_get(env, pt) != MAP_GROUND)
			break ;
		pt.x += delta.x;
		pt.y += delta.y;
	}
	return (pt);
}

static void		draw_wall(t_env *env, int x, t_pt pt)
{
	int				wall;

	wall = (HEIGHT - ((PROJECTION * env->map.block)
		/ ft_dist(pt, env->player.pos))) / 2;
	ft_drawvert(&(env->img), PT(x, 0), wall, COLOR_SKY);
	ft_drawvert(&(env->img), PT(x, wall), HEIGHT - wall - wall, COLOR_CORNER);
	ft_drawvert(&(env->img), PT(x, HEIGHT - wall), wall, COLOR_GROUND);
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
		draw_wall(env, x, ft_nearest(env->player.pos, cast_x(env,
			dir + env->player.dir), cast_y(env, dir + env->player.dir)));
		x++;
		dir += delta;
	}
}
*/
