/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:21:29 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/15 15:45:35 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Init the Exit frames to the collectibles   */
/* animation and puts the image to the struct */

void	ft_init_collectible(t_base *base)
{
	static int	i;
	static int	pace;

	base->img_c.img_w[0] = mlx_xpm_file_to_image(base->mlx, \
	"tile_c0.xpm", &base->img_c.width, &base->img_c.height);
	base->img_c.img_w[1] = mlx_xpm_file_to_image(base->mlx, \
	"tile_c1.xpm", &base->img_c.width, &base->img_c.height);
	base->img_c.img_w[2] = mlx_xpm_file_to_image(base->mlx, \
	"tile_c2.xpm", &base->img_c.width, &base->img_c.height);
	base->img_c.img = base->img_c.img_w[i];
	if (pace++ < 7)
		return ;
	pace = 0;
	i++;
	if (i == 2)
		i = 0;
}

/* Check if the player colide with it     */
/* and changes it to a free tile (tile_0) */
/* or prints the collectible on the map   */

void	puff(t_base *base, int i, int j)
{
	if (base->img_p.x == j * 32 && base->img_p.y == i * 32)
	{
		base->map[i][j] = '0';
		base->img_c.counter++;
	}
	else
	{
		mlx_put_image_to_window(base->mlx, base->window, \
		base->img_c.img, base->img_c.x, base->img_c.y);
	}
}

/* Updates the frame of the exit   */
/* Checks the collectible position */

void	update_collectible(t_base *base)
{
	int	i;
	int	j;

	i = -1;
	ft_init_collectible(base);
	while (base->map[++i])
	{
		j = -1;
		while (base->map[i][++j])
		{
			if (base->map[i][j] == 'C')
			{
				base->img_c.x = j * 32;
				base->img_c.y = i * 32;
				puff(base, i, j);
			}
		}
	}
}
