/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:55:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/11 11:41:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/*
** Header
** width:height;spawn.x:spawn.y:spawn_dir
**
** Data
** 0	Ground
** 1	Wall
*/
static void		parse_header(t_map *map, int fd)
{
	t_buff			header;

	if (get_next_line(fd, &(header.data)) < 1)
		error("Empty map");
	header.i = 0;
	header.length = ft_strlen(header.data);
	map->width = ft_parseint(&header);
	ft_parse(&header, ": ");
	map->height = ft_parseint(&header);
	if (map->width <= 0 || map->height <= 0)
		error("Map too small");
	ft_parse(&header, "; ");
	map->spawn.x = ft_parseint(&header);
	ft_parse(&header, ": ");
	map->spawn.y = ft_parseint(&header);
	ft_parse(&header, ": ");
	map->spawn_dir = ft_parseint(&header);
	if (map->spawn.x <= 0 || map->spawn.y <= 0)
		error("Map too small");
}

static void		parse_map(t_map *map, int fd)
{
	t_buff			line;
	t_pt			pos;

	pos.y = 0;
	map->data = MAL(int*, map->height);
	while (get_next_line(fd, &(line.data)) >= 1)
	{
		if (pos.y >= map->height)
			break ;
		line.i = 0;
		line.length = ft_strlen(line.data);
		pos.x = 0;
		map->data[pos.y] = MAL(int, map->width);
		while (pos.x < map->width)
		{
			map->data[pos.y][pos.x] = ft_parseint(&line);
			ft_parsespace(&line);
			pos.x++;
		}
		pos.y++;
	}
	if (pos.y < map->height)
		error("Bad map");
}

int				map_get(t_env *env, t_pt pt)
{
	return (env->map.data[pt.y / BLOCK_SIZE][pt.x / BLOCK_SIZE]);
}

void			map_ini(t_map *map, const char *file)
{
	int				fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(strerror(errno));
	parse_header(map, fd);
	parse_map(map, fd);
	close(fd);
	map->width *= BLOCK_SIZE;
	map->height *= BLOCK_SIZE;
}
