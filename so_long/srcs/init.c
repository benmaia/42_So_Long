/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:21:45 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/04 21:26:00 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_structer *ft_init_struct(void)
{
	t_structer	*structer;
	
	structer = (t_structer *)malloc(sizeof(t_structer));
	if (!structer)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	structer->win_x = IMG_WIDTH;
	structer->win_y = IMG_HEIGHT;
	structer->move_counter = 0;
	structer->map_x = 0;
	structer-> map_y = 0;
	structer->px = 0;
	structer->py = 0;
	structer->x = 0;
	structer->y = 0;
	structer->map = NULL;
	structer->img_0.img = NULL;
	structer->img_p.img = NULL;
	return (structer);
}

void	ft_init_window(t_structer *structer)
{
	int x;
	int y;

	x = 0;
	y = 0;
	structer->mlx = mlx_init();
	structer->window = mlx_new_window(structer->mlx, structer->win_x, structer->win_y, "So Long");
	
	structer->img_0.img = mlx_xpm_file_to_image(structer->mlx, "oooo.xpm", &structer->img_0.width, &structer->img_0.height);
	mlx_put_image_to_window(structer->mlx, structer-> window, structer->img_0.img, x, y);
	structer->img_p.img = mlx_xpm_file_to_image(structer->mlx, "char.xpm", &structer->img_p.width, &structer->img_p.height);
	mlx_put_image_to_window(structer->mlx, structer-> window, structer->img_p.img, x, y);
	// mlx_clear_window(structer->mlx, structer->window);
	// structer->img_0.img = mlx_xpm_file_to_image(structer->mlx, "oooo.xpm", &structer->img_0.width, &structer->img_0.height);
	// mlx_put_image_to_window(structer->mlx, structer-> window, structer->img_0.img, x, y);
	// structer->img_p.img = mlx_xpm_file_to_image(structer->mlx, "char.xpm", &structer->img_p.width, &structer->img_p.height);
	// mlx_put_image_to_window(structer->mlx, structer-> window, structer->img_p.img, 100, 100);
}


// void	ft_init_map(t_structer *structer)
// {
// 	int	i;
// 	int	y;
// 	int	x;
// 	int	y;
	
// 	i = -1;
// 	while (++i < structer->map_y)
// 	{
// 		j = -1;
// 		while (++j < structer->map_x)
// 		{
// 			x = IMG_HEIGHT * j;
// 			y = IMG_WIDTH * i;
// 			if (structer->map[i][j] == 0)
// 				mlx_put_image_to_window = ()
// 		}
		
// 	}
// }