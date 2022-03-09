/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:21:45 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/09 13:03:41 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_base	*ft_init_struct(void)
{
	t_base	*base;

	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	base->win_x = 1000;
	base->win_y = 1000;
	base->move_counter = 0;
	return (base);
}

/* Set the value of the keys to 0 */
/* to be able to walk while press */

void	init_keys(t_base *base)
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
	base->img_p.x = 0;
	base->img_p.y = 0;
	base->img_p.pace = 6;
	ft_init_player_animation(base);
	mlx_put_image_to_window(base->mlx, base-> window, \
	base->img_p.img_s[0], 0, 0);
	base->img_p.img = base->img_p.img_s;
}

/* Read the .ber file and builds */
/* the map accordingly           */

void	init_map(t_base *base)
{
	base->img_0.img = mlx_xpm_file_to_image(base->mlx, \
	"test.xpm", &base->img_0.width, &base->img_0.height);
	mlx_put_image_to_window(base->mlx, base-> window, base->img_0.img, 0, 0);
}

/* Setup the game to the window */

void	ft_init_window(t_base *base)
{
	base->mlx = mlx_init();
	base->window = mlx_new_window(base->mlx, base->win_x, \
	base->win_y, "So Long");
	init_keys(base);
	init_map(base);
	ft_init_player(base);
	ft_init_struct();
}
