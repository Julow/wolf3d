/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:14:12 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/10 23:02:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>

int				main(int argc, char **argv)
{
	void			*mlx;
	t_env			*env;

	if (argc <= 1)
		return (ft_putstr_fd("wolf3d: Please specify a map\n", 2), 1);
	if ((mlx = mlx_init()) == NULL)
		return (ft_putstr_fd("wolf3d: mlx: Cannot init mlx\n", 2), 1);
	if ((env = env_new(mlx)) == NULL)
		return (ft_putstr_fd("wolf3d: mlx: Cannot create image\n", 2), 1);
	map_ini(&(env->map), argv[1]);
	env_start(env);
	ft_putstr_fd("wolf3d: Cannot init game\n", 2);
	return (0);
}
