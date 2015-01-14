/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:55:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/14 14:59:44 by jaguillo         ###   ########.fr       */
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
** width:height;block_size;camera_h;spawn.x:spawn.y:spawn_dir
** -------------
** Data
** 0	Ground
** 1	Wall
*/
static void		parse_header(t_map *map, int fd)
{
	t_buff			header;

	if (get_next_line(fd, &header) < 1)
		error("Empty map");
	header.i = 0;
	header.length = ft_strlen(header.data);
	map->width = ft_parseint(&header);
	ft_parse(&header, ": ");
	map->height = ft_parseint(&header);
	if (map->width <= 0 || map->height <= 0)
		error("Map: too small");
	ft_parse(&header, "; ");
	map->block_size = ft_parseint(&header);
	if (map->block_size <= 0)
		error("Map: bad block size");
	ft_parse(&header, "; ");
	map->camera_h = ft_parseint(&header);
	ft_parse(&header, "; ");
	map->spawn.x = ft_parseint(&header);
	ft_parse(&header, ": ");
	map->spawn.y = ft_parseint(&header);
	ft_parse(&header, ": ");
	map->spawn_dir = ft_parseint(&header);
	if (map->spawn.x <= 0 || map->spawn.y <= 0)
		error("Map: bad spawn location");
}

static void		parse_map(t_map *map, int fd)
{
	t_buff			line;
	t_pt			pos;

	pos.y = 0;
	map->data = MAL(int*, map->height);
	while (get_next_line(fd, &line) >= 1)
	{
		if (pos.y >= map->height)
			error("Map: map height is too small");
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
		error("Map: map height is too big");
}

int				map_get(t_env *env, t_pt pt)
{
	if (pt.x < 0 || pt.y < 0 || pt.x >= env->map.width
		|| pt.y >= env->map.height)
		return (MAP_WALL);
	return (env->map.data[pt.y / env->map.block_size][pt.x
		/ env->map.block_size]);
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
	map->width *= map->block_size;
	map->height *= map->block_size;
}
