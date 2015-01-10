/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:19:24 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/10 22:48:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>

int				expose_hook(void *param)
{
	t_env			*env;

	env = (t_env*)param;
	env->redraw = FALSE;
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}

int				key_hook(int keycode, void *param)
{
	if (keycode == 65307)
		env_exit(param);
	return (0);
}

int				loop_hook(void *param)
{
	if (((t_env*)param)->redraw)
		expose_hook(param);
	return (0);
}
