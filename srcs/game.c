/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 11:12:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/18 13:35:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void			init_game(t_env *env)
{
	env->player.pos = env->map.spawn;
	env->player.dir = env->map.spawn_dir;
}

void			draw_gui(t_env *env)
{
	t_pt			pt;

	pt.y = -1;
	while (++pt.y < env->map.height)
	{
		pt.x = -1;
		while (++pt.x < env->map.width)
		{
			if (env->map.data[pt.y][pt.x] == MAP_GROUND)
				ft_drawrectf(&(env->img),
					RECT(pt.x * MINIMAP_BLOCK + MINIMAP_OFFSET,
						pt.y * MINIMAP_BLOCK + MINIMAP_OFFSET,
						MINIMAP_BLOCK - 1, MINIMAP_BLOCK - 1), MINIMAP_COLOR);
		}
	}
	pt = PT(env->player.pos.x * MINIMAP_BLOCK / env->map.block + MINIMAP_OFFSET,
		env->player.pos.y * MINIMAP_BLOCK / env->map.block + MINIMAP_OFFSET);
	ft_drawline(&(env->img), pt, PT(cos(env->player.dir) * 5 + pt.x,
		sin(env->player.dir) * 5 + pt.y), C(0xFFFF0000));
}
