/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 23:02:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/11 17:10:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>
#include <stdlib.h>

void			error(char *error)
{
	ft_putstr_fd("wolf3d: ", 2);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

double			ft_dist(t_pt p1, t_pt p2)
{
	p1 = PT(p1.x - p2.x, p1.y - p2.y);
	return (sqrt((p1.x * p1.x) + (p1.y * p1.y)));
}

t_pt			ft_nearest(t_pt pos, t_pt p1, t_pt p2)
{
	const t_pt		t1 = PT(p1.x - pos.x, p1.y - pos.y);
	const t_pt		t2 = PT(p2.x - pos.x, p2.y - pos.y);

	if (((t1.x * t1.x) + (t1.y * t1.y)) > ((t2.x * t2.x) + (t2.y * t2.y)))
		return (p1);
	return (p2);
}

void			ft_drawvert(t_image *img, t_pt pt, int height, t_color color)
{
	int				pos;
	t_color			tmp;

	if (pt.y < 0)
	{
		height += pt.y;
		pt.y = 0;
	}
	if ((pt.y + height) > img->height)
		height = img->height - pt.y;
	if (pt.x < 0 || pt.x >= img->width || height <= 0 || pt.y >= img->height)
		return ;
	pos = (img->width * pt.y + pt.x) * img->opp;
	while (height-- > 0)
	{
		tmp = color;
		if (ALPHA(tmp))
			ft_resalpha(&tmp, ft_imagepos(img, pos));
		ft_imageput(img, pos, tmp);
		pos += img->width * img->opp;
	}
}
