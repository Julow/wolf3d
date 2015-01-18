/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:14:12 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/18 20:13:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>

int				main(int argc, char **argv)
{
	void			*mlx;
	t_env			*env;

	if (argc <= 1)
		error("Please specify a map");
	if ((mlx = mlx_init()) == NULL)
		error("mlx: Cannot init mlx");
	env = env_new(mlx);
	map_ini(&(env->map), argv[1]);
	init_game(env);
	env_start(env);
	return (0);
}
