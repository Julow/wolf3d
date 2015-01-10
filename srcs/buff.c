/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 23:11:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/10 23:37:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_parse(t_buff *buff, const char *parse)
{
	while (buff->i < buff->length)
	{
		if (ft_strchr(parse, buff->data[buff->i]) == NULL)
			break ;
		buff->i++;
	}
}

int				ft_parseint(t_buff *buff)
{
	int				nb;
	t_bool			negatif;

	if (buff->i >= buff->length)
		return (0);
	negatif = FALSE;
	nb = 0;
	if ((buff->data[buff->i] == '-' && (negatif = TRUE))
		|| buff->data[buff->i] == '+')
		buff->i++;
	while (buff->i < buff->length && ft_isdigit(buff->data[buff->i]))
		nb = nb * 10 + (buff->data[buff->i++] - '0');
	return (negatif ? -nb : nb);
}

void			ft_parsespace(t_buff *buff)
{
	while (buff->i < buff->length && ft_isspace(buff->data[buff->i]))
		buff->i++;
}
