/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:23:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/10 22:58:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>
#include <stdlib.h>

static void		ft_imageini(t_image *img, void *mlx, t_pt size)
{
	int				bpp;

	img->img = mlx_new_image(mlx, size.x, size.y);
	img->data = (t_byte*)mlx_get_data_addr(img->img, &bpp, &img->l_size,
		&img->endian);
	img->width = size.x;
	img->height = size.y;
	img->opp = bpp / 8;
}

t_env			*env_new(void *mlx)
{
	t_env			*env;

	if ((env = MAL1(t_env)) == NULL)
		return (NULL);
	env->mlx = mlx;
	env->win = NULL;
	env->redraw = FALSE;
	ft_imageini(&(env->img), mlx, PT(WIDTH, HEIGHT));
	return (env);
}

void			env_start(t_env *env)
{
	if ((env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "")) == NULL)
		return ;
	mlx_expose_hook(env->win, &expose_hook, env);
	mlx_key_hook(env->win, &key_hook, env);
	mlx_key_hook(env->win, &key_hook, env);
	mlx_loop_hook(env->mlx, &loop_hook, env);
	mlx_loop(env->mlx);
}

void			env_exit(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img.img);
	free(env);
	exit(0);
}
