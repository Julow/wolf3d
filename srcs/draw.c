/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:38:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 09:05:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static t_color	wall_color(t_pt p1, t_pt p2)
{
	p1.x -= p2.x;
	p1.y -= p2.y;
	if (p1.x < 0)
		return (COLOR_EST);
	if (p1.x > 0)
		return (COLOR_WEST);
	if (p1.y < 0)
		return (COLOR_NORTH);
	if (p1.y > 0)
		return (COLOR_SUD);
	return (C(0xFF000000));
}

static void		cast(t_env *env, double dir, int x)
{
	t_lpt			delta;
	t_lpt			pos;
	int				wall;
	t_pt			tmp;
	t_pt			last;

	pos = LPT(env->player.pos.x, env->player.pos.y);
	last = env->player.pos;
	delta = LPT(cos(dir), sin(dir));
	while (1)
	{
		tmp = PT((int)pos.x, (int)pos.y);
		if (map_get(env, tmp) != GROUND)
			break ;
		last = tmp;
		pos.x += delta.x;
		pos.y += delta.y;
	}
	wall = (HEIGHT - (PROJECTION * BLOCK_SIZE)
		/ ft_dist(tmp, env->player.pos)) / 2;
	ft_drawvert(&(env->img), PT(x, wall), HEIGHT - wall - wall, wall_color(last,
		PT((int)pos.x, (int)pos.y)));
	ft_drawvert(&(env->img), PT(x, HEIGHT - wall), wall, C(0xFF222222));
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
