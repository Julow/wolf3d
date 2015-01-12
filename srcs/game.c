/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 11:12:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 09:06:44 by jaguillo         ###   ########.fr       */
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
	ft_drawline(&(env->img), PT(80, 80), PT(cos(env->player.dir) * 20 + 80,
		sin(env->player.dir) * 20 + 80), C(0xFFFF0000));
}
