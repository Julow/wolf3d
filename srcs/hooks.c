/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:19:24 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/11 17:05:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

static void		draw_debug(t_env *env)
{
	t_string		tmp;

	ft_stringini(&tmp);
	ft_stringadd(&tmp, "X: ");
	ft_stringaddi(&tmp, env->player.pos.x);
	ft_stringadd(&tmp, " ; Y: ");
	ft_stringaddi(&tmp, env->player.pos.y);
	ft_stringadd(&tmp, " ; (");
	ft_stringaddd(&tmp, env->player.dir, 6);
	ft_stringadd(&tmp, ")");
	mlx_string_put(env->mlx, env->win, 20, 30, 0xFFFFFFFF, tmp.content);
	free(tmp.content);
}

int				expose_hook(void *param)
{
	t_env			*env;

	env = (t_env*)param;
	env->redraw = FALSE;
	ft_imageclr(&(env->img));
	draw_map(env);
	draw_gui(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	draw_debug(env);
	return (0);
}

static void		player_move(t_env *env, int speed)
{
	env->player.pos.x += cos(env->player.dir) * speed;
	env->player.pos.y += sin(env->player.dir) * speed;
}

int				key_hook(int keycode, void *param)
{
	t_env			*env;

	env = (t_env*)param;
	if (keycode == KEY_ESC)
		env_exit(param);
	else if (keycode == KEY_LEFT)
		env->player.dir -= 0.2;
	else if (keycode == KEY_RIGHT)
		env->player.dir += 0.2;
	else if (keycode == KEY_UP)
		player_move(env, SPEED);
	else if (keycode == KEY_DOWN)
		player_move(env, -SPEED);
	else
		return (0);
	env->redraw = TRUE;
	return (0);
}

int				loop_hook(void *param)
{
	if (((t_env*)param)->redraw)
		expose_hook(param);
	return (0);
}
