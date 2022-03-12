/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:55:00 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/12 15:00:43 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Gets the file descriptor of the */
/* .ber file and returns it        */

int	get_fd(char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if ((fd) == -1)
	{
		ft_printf("file opening failed\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("Success open fd\n");
	return (fd);
}

/* With the fd, the reap_map function */
/* will read line by line with the    */
/* get_next_line, and store it inside */
/* one string. After the map is fully */
/* store inside 1 string the ft_split */
/* will split the map in a            */
/* multi-dimension array to store the */
/* map in a matrix and can be easily  */
/* acesseble every position of the map*/

char	**read_map(int fd)
{
	char	*str;
	char	*buf;
	char	**map;

	str = ft_strdup("");
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		str = ft_strjoin(str, buf);
		buf = get_next_line(fd);
	}
	ft_printf("Success reap_map\n");
	map = ft_split(str, '\n');
	free(buf);
	buf = NULL;
	free(str);
	str = NULL;
	ft_printf("Success free GNL\n");
	return (map);
}

/* Checks if the map it's closed */
/* by walls at every side .      */
/* Around the map everything     */
/* has to have the value of '1'  */

int	check_map_close(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[0][j] != '1')
				return (0);
			if (map[i][0] != '1')
				return (0);
		}
		if (map[i][--j] != '1')
			return (0);
	}
	j = -1;
	i -= 1;
	while (map[i][++j])
		if (map[i][j] != '1')
			return (0);
	return (1);
}

/* Checks if the map has te right */
/* size. That every line is the   */
/* same size!                     */

int	check_map_size(t_base *base, char **map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		j = -1;
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (ft_printf("Inconsistent map size[1]\n") - 25);
		while (map[i][++j])
			;
	}
	base->win_x = j * 32;
	base->win_y = i * 32;
	return (1);
}

/* Checks if the map it's has all      */
/* the necessary values to start.      */
/* Every map need at least one 'C'     */
/* [collectible], one 'E' [exit]       */
/* and 1 'P' [starting player position]*/
/* also it stores the position [x][y]  */
/* of last 'P' it finds, to be passed  */
/* to the paint function so it knows   */
/* where to start!                     */

int	check_map_playble(char **map)
{
	int			i;
	int			j;
	static int	e;
	static int	c;
	static int	p;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				c++;
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
		}
	}
	if (c < 1 || p < 1 || e < 1)
		return (ft_printf("The map have to contain at least one \
of each char '1' '0' 'C' 'P' 'E'\n") - 70);
	return (1);
}
