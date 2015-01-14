/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 23:02:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/14 14:42:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>
#include <stdlib.h>

void			error(char *error)
{
	ft_putstr_fd("wolf3d: ", 2);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

inline t_pt		round_block(t_env *env, t_pt pt)
{
	const int		b_size = env->map.block_size;

	pt.x = pt.x / b_size * b_size + (b_size / 2);
	pt.y = pt.y / b_size * b_size + (b_size / 2);
	return (pt);
}

double			ft_dist(t_pt p1, t_pt p2)
{
	p1 = PT(p1.x - p2.x, p1.y - p2.y);
	return (sqrt((p1.x * p1.x) + (p1.y * p1.y)));
}

int				ft_dist2(t_pt p1, t_pt p2)
{
	p1 = PT(p1.x - p2.x, p1.y - p2.y);
	return ((p1.x * p1.x) + (p1.y * p1.y));
}

t_pt			ft_nearest(t_pt pos, t_pt p1, t_pt p2)
{
	const t_pt		t1 = PT(p1.x - pos.x, p1.y - pos.y);
	const t_pt		t2 = PT(p2.x - pos.x, p2.y - pos.y);

	if (((t1.x * t1.x) + (t1.y * t1.y)) > ((t2.x * t2.x) + (t2.y * t2.y)))
		return (p1);
	return (p2);
}
