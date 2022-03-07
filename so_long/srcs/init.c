/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:21:45 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/07 21:03:15 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	init_keys(t_base *base)
{
	base-> keys.a = 0;
	base-> keys.d = 0;
	base-> keys.w = 0;
	base-> keys.s = 0;
	base-> keys.esc = 0;
}

void	init_player(t_base *base)
{
	base->img_p.x = 0;
	base->img_p.y = 0;
	base->img_p.pace = 3;
	base->img_p.img_s = mlx_xpm_file_to_image(base->mlx, \
	"front.xpm", &base->img_p.width, &base->img_p.height);
	mlx_put_image_to_window(base->mlx, base-> window, base->img_p.img_s, 0, 0);
	base->img_p.img_a = mlx_xpm_file_to_image(base->mlx, \
	"left.xpm", &base->img_p.width, &base->img_p.height);
	base->img_p.img_d = mlx_xpm_file_to_image(base->mlx, \
	"right.xpm", &base->img_p.width, &base->img_p.height);
	base->img_p.img_w = mlx_xpm_file_to_image(base->mlx, \
	"back.xpm", &base->img_p.width, &base->img_p.height);
	base->img_p.img = base->img_p.img_s;
}

void	init_map(t_base *base)
{
	base->img_0.img = mlx_xpm_file_to_image(base->mlx, \
	"oooo.xpm", &base->img_0.width, &base->img_0.height);
	mlx_put_image_to_window(base->mlx, base-> window, base->img_0.img, 0, 0);
}

void	ft_init_window(t_base *base)
{
	base->mlx = mlx_init();
	base->window = mlx_new_window(base->mlx, base->win_x, \
	base->win_y, "So Long");
	init_keys(base);
	init_map(base);
	init_player(base);
	ft_init_struct();
}
