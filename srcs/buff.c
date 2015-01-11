/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 23:11:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/11 11:36:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_parse(t_buff *buff, const char *parse)
{
	while (buff->i < buff->length)
	{
		if (ft_strchr(parse, B(buff)) == NULL)
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
	if ((B(buff) == '-' && (negatif = TRUE)) || B(buff) == '+')
		buff->i++;
	while (buff->i < buff->length && ft_isdigit(B(buff)))
		nb = nb * 10 + (buff->data[buff->i++] - '0');
	return (negatif ? -nb : nb);
}

double			ft_parsedouble(t_buff *buff)
{
	double			nb;
	double			part;
	t_bool			negatif;

	negatif = (B(buff) == '-') ? TRUE : FALSE;
	if (B(buff) == '-' || B(buff) == '+')
		buff->i++;
	nb = 0.0;
	while (ft_isdigit(B(buff)))
		nb = nb * 10 + (buff->data[buff->i++] - '0');
	if (B(buff) == '.' || B(buff) == ',')
	{
		part = 0.0;
		while (ft_isdigit(buff->data[++buff->i]))
			;
		while (ft_isdigit(buff->data[--buff->i]))
			part = (part + (B(buff) - '0')) / 10.0;
		nb += part;
	}
	return (negatif ? -nb : nb);
}

void			ft_parsespace(t_buff *buff)
{
	while (buff->i < buff->length && ft_isspace(B(buff)))
		buff->i++;
}
