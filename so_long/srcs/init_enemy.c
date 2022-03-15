/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:41:19 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/15 15:45:36 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Init the Enemy frames to animation */
/* Puts the image to the struct      */

void	ft_init_enemy(t_base *base)
{
	static int	i;
	static int	pace;

	base->img_x.img_w[0] = mlx_xpm_file_to_image(base->mlx, \
	"tile_d0.xpm", &base->img_x.width, &base->img_x.height);
	base->img_x.img_w[1] = mlx_xpm_file_to_image(base->mlx, \
	"tile_d1.xpm", &base->img_x.width, &base->img_x.height);
	base->img_x.img_w[2] = mlx_xpm_file_to_image(base->mlx, \
	"tile_d2.xpm", &base->img_x.width, &base->img_x.height);
	base->img_x.img = base->img_x.img_w[i];
	if (pace++ < 7)
		return ;
	pace = 0;
	i++;
	if (i == 2)
		i = 0;
}

/* Check if the player colide with it */
/* and changes die, (close the game)  */
/* or prints the enemy the map        */

void	puff_enemy(t_base *base, int i, int j)
{
	if (base->img_p.x == j * 32 && base->img_p.y == i * 32)
		exit_s(base);
	else
		mlx_put_image_to_window(base->mlx, base->window, \
		base->img_x.img, base->img_x.x, base->img_x.y);
}

/* Updates the frame of the enemy   */
/* Checks the enemy position */

void	update_enemy(t_base *base)
{
	int	i;
	int	j;

	i = -1;
	ft_init_enemy(base);
	while (base->map[++i])
	{
		j = -1;
		while (base->map[i][++j])
		{
			if (base->map[i][j] == 'X')
			{
				base->img_x.x = j * 32;
				base->img_x.y = i * 32;
				puff_enemy(base, i, j);
			}
		}
	}
}
