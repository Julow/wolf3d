/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:14:12 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/09 16:31:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>

int				main(int argc, char **argv)
{
	void			*mlx;
	t_env			*env;

	if ((mlx = mlx_init()) == NULL)
		error("mlx: Cannot init mlx");
	env = env_new(mlx);
	map_ini(&(env->map));
	init_game(env);
	env_start(env);
	(void)argc;
	(void)argv;
	return (0);
}
