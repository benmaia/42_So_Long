/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:02:18 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/07 21:03:24 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_update(t_base *base, int *temp)
{
	if (base->keys.w && !base->keys.s)
	{
		base->img_p.img = base->img_p.img_w;
		base->img_p.y -= base->img_p.pace;
		*temp += 1;
	}
	if (!base->keys.w && base->keys.s)
	{
		base->img_p.img = base->img_p.img_s;
		base->img_p.y += base->img_p.pace;
		*temp += 1;
	}
	if (base->keys.a && !base->keys.d)
	{
		base->img_p.img = base->img_p.img_a;
		base->img_p.x -= base->img_p.pace;
		*temp += 1;
	}
	if (!base->keys.a && base->keys.d)
	{
		base->img_p.img = base->img_p.img_d;
		base->img_p.x += base->img_p.pace;
		*temp += 1;
	}
	return (*temp);
}

void	ft_move_counter(t_base *base)
{
	static int	counter;
	static int	temp;

	temp = ft_update(base, &temp);
	if (temp >= 8)
	{
		temp = 0;
		counter++;
	}
	ft_printf("Number of moves: %i\n", counter);
}

void	ft_paint(t_base *base)
{
	mlx_put_image_to_window(base->mlx, \
	base->window, base->img_0.img, 0, 0);
	mlx_put_image_to_window(base->mlx, \
	base->window, base->img_p.img, \
	base->img_p.x, base->img_p.y);
}
