/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:29:44 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/11 13:28:21 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	map_start(t_base *base)
// {
// 	int	x;
// 	int	y;

// 	x = -1;
// 	base->maps = malloc(sizeof(void **) * (base->win_y / 32));
// 	while (++x < (base->win_y / 32))
// 	{
// 		y = -1;
// 		base->maps[x] = malloc(sizeof(void *) * (base->win_x / 32));
// 		while (++y < (base->win_x / 32))
// 		{
// 			base->maps[x][y] = 0;
// 			if (base->map[x][y] == '1')
// 				base->maps[x][y] = base->img_1.img;
// 			else
// 				base->maps[x][y] = base->img_0.img;
// 		}
// 	}
// }

/* It stores the images */
/* in the right struct  */

void	ft_init_map(t_base *base)
{
	base->img_0.img = mlx_xpm_file_to_image(base->mlx, \
	"tile_0.xpm", &base->img_0.width, &base->img_0.height);
	base->img_1.img = mlx_xpm_file_to_image(base->mlx, \
	"tile_1.xpm", &base->img_1.width, &base->img_1.height);
	base->img_c.img = mlx_xpm_file_to_image(base->mlx, \
	"tile_c.xpm", &base->img_c.width, &base->img_c.height);
	base->img_e.img = mlx_xpm_file_to_image(base->mlx, \
	"tile_e.xpm", &base->img_e.width, &base->img_e.height);
}

/* Calls the checkers to see */
/* if the map is valid to    */
/* start the so_lon game     */

int	ft_checker(t_base *base, char **argv)
{
	int		fd;

	fd = get_fd(argv);
	base->map = read_map(fd);
	if (!check_map_size(base, base->map))
	{
		ft_printf("Size Error [1]\n");
		return (0);
	}
	if (!check_map_close(base->map))
	{
		ft_printf("The map has to be close by walls [2]\n");
		return (0);
	}
	if (!check_map_playble(base->map))
	{
		ft_printf("The map is not playable [3]\n");
		return (0);
	}
	return (1);
}

/* Reads the map, and prints */
/* it in the right place     */

void	map_print(t_base *base)
{
	int	i;
	int	j;

	i = -1;
	while (base->map[++i])
	{
		j = -1;
		while (base->map[i][++j])
		{
			if (base->map[i][j] == '1')
				mlx_put_image_to_window(base->mlx, base-> window, \
				base->img_1.img, j * 32, i * 32);
			else if (base->map[i][j] == 'C')
				mlx_put_image_to_window(base->mlx, base-> window, \
				base->img_c.img, j * 32, i * 32);
			else if (base->map[i][j] == 'E')
				mlx_put_image_to_window(base->mlx, base-> window, \
				base->img_e.img, j * 32, i * 32);
			else
				mlx_put_image_to_window(base->mlx, base-> window, \
				base->img_0.img, j * 32, i * 32);
		}
	}
}
