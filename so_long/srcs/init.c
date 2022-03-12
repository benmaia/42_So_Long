/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:21:45 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/12 14:57:08 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_base	*ft_init_struct(void)
{
	t_base	*base;

	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
	{
		return (0);
	}
	base->move_counter = 0;
	return (base);
}

/* Set the value of the keys to 0 */
/* to be able to walk while press */

void	ft_init_keys(t_base *base)
{
	base-> keys.a = 0;
	base-> keys.d = 0;
	base-> keys.w = 0;
	base-> keys.s = 0;
	base-> keys.esc = 0;
}

/*Set the 4 images to the player, his */
/* pace and his initial position      */

void	ft_init_player(t_base *base)
{
	int	i;
	int	j;

	i = -1;
	while (base->map[++i])
	{
		j = -1;
		while (base->map[i][++j])
		{
			if (base->map[i][j] == 'P')
			{
				base->img_p.x = j * 32;
				base->img_p.y = i * 32;
			}
		}
	}
	base->img_p.pace = 4;
	ft_init_player_animation(base);
	base->img_p.img = base->img_p.img_s[0];
	mlx_put_image_to_window(base->mlx, base-> window, \
	base->img_p.img, base->img_p.x, base->img_p.y);
}

/* Setup the game to the window */

void	ft_init_window(t_base *base)
{
	base->mlx = mlx_init();
	base->window = mlx_new_window(base->mlx, base->win_x, \
	base->win_y, "So Long");
	ft_init_keys(base);
	ft_init_map(base);
	ft_init_player(base);
	ft_init_struct();
}
