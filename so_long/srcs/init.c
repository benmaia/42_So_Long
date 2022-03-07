/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paijavai <paijavai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:21:45 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/06 14:26:20 by paijavai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_structer *ft_init_struct(void)
{
	t_structer	*structer;
	
	structer = (t_structer *)malloc(sizeof(t_structer));
	if (!structer)
	{
		//write(1, "Error\n", 6);
		return (0);
	}
	structer->win_x = 1000;
	structer->win_y = 1000;
	structer->move_counter = 0;
	structer->map_x = 0;
	structer-> map_y = 0;
	structer->px = 0;
	structer->py = 0;
	structer->x = 0;
	structer->y = 0;
	structer->map = NULL;
	structer->img_0.img_d = NULL;
	structer->img_p.img_d = NULL;
	return (structer);
}

void	ft_init_img(t_structer *structer)
{
	structer->img_0.img_d = mlx_xpm_file_to_image(structer->mlx, "oooo.xpm", &structer->img_0.width, &structer->img_0.height);
	mlx_put_image_to_window(structer->mlx, structer-> window, structer->img_0.img_d, 0, 0);
	structer->img_p.img_d = mlx_xpm_file_to_image(structer->mlx, "front.xpm", &structer->img_p.width, &structer->img_p.height);
	mlx_put_image_to_window(structer->mlx, structer-> window, structer->img_p.img_d, 0, 0);
	structer->img_p.img_l = mlx_xpm_file_to_image(structer->mlx, "left.xpm", &structer->img_p.width, &structer->img_p.height);
	structer->img_p.img_r = mlx_xpm_file_to_image(structer->mlx, "right.xpm", &structer->img_p.width, &structer->img_p.height);
	structer->img_p.img_u = mlx_xpm_file_to_image(structer->mlx, "back.xpm", &structer->img_p.width, &structer->img_p.height);
}

void	ft_init_window(t_structer *structer)
{
	structer->mlx = mlx_init();
	structer->window = mlx_new_window(structer->mlx, structer->win_x, structer->win_y, "So Long");
	ft_init_img(structer);
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
