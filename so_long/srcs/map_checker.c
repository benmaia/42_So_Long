/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:55:00 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/11 00:34:32 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	check_map_size(t_base *base, char **map)
{
	int	i;
	int	j;

	i = -1;
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

int	check_map_playble(t_base *base, char **map)
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
			{
				p++;
				base->img_p.x = j * 32;
				base->img_p.y = i * 32;
			}
			if (map[i][j] == 'E')
				e++;
		}
	}
	if (c < 1 || p < 1 || e < 1)
		return (ft_printf("The map have to contain at least one \
of each char '1' '0' 'C' 'P' 'E'\n") - 70);
	return (1);
}
