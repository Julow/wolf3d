/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 23:02:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/10 23:06:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>

void			error(char *error)
{
	ft_putstr_fd("wolf3d: ", 2);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
