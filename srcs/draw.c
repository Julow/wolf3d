/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:38:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/18 11:20:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static t_pt		cast_y(t_env *env, double dir)
{
	t_pt			delta;
	t_pt			pt;

	delta.x = (cos(dir) > 0) ? env->map.block : -env->map.block;
	delta.y = env->map.block * tan(dir);
	pt.x = (env->player.pos.x + delta.x) / env->map.block * env->map.block;
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
	pt.y = (env->player.pos.y + delta.y) / env->map.block * env->map.block;
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
		draw_wall(env, x, ft_nearest(env->player.pos,
			cast_x(env, dir + env->player.dir), cast_y(env, dir + env->player.dir)));
		x++;
		dir += delta;
	}
}
