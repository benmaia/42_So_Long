/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:46:51 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/15 15:45:33 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Free memory allocations of the map */

void	free_map(t_base *base)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (base->map[++i])
		free(base->map[i]);
	free(base->map);
	mlx_destroy_image(base->mlx, base->img_0.img);
	mlx_destroy_image(base->mlx, base->img_1.img);
}

/* Free memory allocations of the player */

void	free_player(t_base *base)
{
	int	i;

	i = -1;
	mlx_destroy_image(base->mlx, base->img_p.img);
	while (++i)
	{
		mlx_destroy_image(base->mlx, base->img_p.img_w[i]);
		mlx_destroy_image(base->mlx, base->img_p.img_s[i]);
		mlx_destroy_image(base->mlx, base->img_p.img_a[i]);
		mlx_destroy_image(base->mlx, base->img_p.img_d[i]);
	}
}

/* Free memory allocations of the enemy */
/* and the collectibles                 */

void	free_collectible_and_enemy(t_base *base)
{
	int	i;

	i = -1;
	mlx_destroy_image(base->mlx, base->img_c.img);
	mlx_destroy_image(base->mlx, base->img_x.img);
	while (++i)
	{
		mlx_destroy_image(base->mlx, base->img_c.img_w[i]);
		mlx_destroy_image(base->mlx, base->img_x.img_w[i]);
	}
}

/* Free memory allocations of the exit */

void	free_exit(t_base *base)
{
	free(base->img_e.img);
	mlx_destroy_image(base->mlx, base->img_e.img);
	mlx_destroy_image(base->mlx, base->img_e.img_w);
}

/* Free memory of everything and exit */

void	exit_s(t_base *base)
{
	free_map(base);
	free_player(base);
	free_collectible_and_enemy(base);
	mlx_destroy_window(base->mlx, base->window);
	free(base);
	exit(EXIT_SUCCESS);
}
