/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:43:18 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/15 15:45:34 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Init the Exit frames to animation */
/* Puts the image to the struct      */

void	ft_init_exit(t_base *base)
{
	static int	i;
	static int	pace;

	base->img_e.img_w[0] = mlx_xpm_file_to_image(base->mlx, \
	"tile_e.xpm", &base->img_e.width, &base->img_e.height);
	base->img_e.img_w[1] = mlx_xpm_file_to_image(base->mlx, \
	"tile_e1.xpm", &base->img_e.width, &base->img_e.height);
	base->img_e.img_w[2] = mlx_xpm_file_to_image(base->mlx, \
	"tile_e2.xpm", &base->img_e.width, &base->img_e.height);
	base->img_e.img = base->img_e.img_w[i];
	if (pace++ < 7)
		return ;
	pace = 0;
	i++;
	if (i == 2)
		i = 0;
}

/* Updates the frame of the exit */
/* Checks the exit position and  */
/* prints it                     */

void	update_exit(t_base *base)
{
	int	i;
	int	j;

	i = -1;
	ft_init_exit(base);
	while (base->map[++i])
	{
		j = -1;
		while (base->map[i][++j])
		{
			if (base->map[i][j] == 'E')
			{
				base->img_e.x = j * 32;
				base->img_e.y = i * 32;
				mlx_put_image_to_window(base->mlx, base->window, \
				base->img_e.img, base->img_e.x, base->img_e.y);
				if (base->img_p.x == j * 32 && base->img_p.y == i * 32)
					if (base->img_c.counter >= base->img_c.nbr)
						exit_s(base);
			}
		}
	}
}
