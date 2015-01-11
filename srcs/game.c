/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 11:12:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/11 14:48:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			init_game(t_env *env)
{
	env->player.pos = env->map.spawn;
	env->player.dir = env->map.spawn_dir;
}

void			draw_gui(t_env *env)
{
	(void)env;
}
