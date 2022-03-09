/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:02:18 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/09 00:13:36 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Has the update receives the  */
/* key value and updates the    */
/* the position, it also counts */
/* how many time it updates.    */
/* I've set it when it updates  */
/* 9 times it counts as 1 step  */

void	ft_move_counter(t_base *base)
{
	static int	counter;

	ft_update(base);
	if (base->move_counter >= 9)
	{
		base->move_counter = 0;
		counter++;
	}
	ft_printf("Number of moves: %i\n", counter);
}

/* Prints the image that the update */
/* chooses as the right one and     */

void	ft_paint(t_base *base)
{
	mlx_put_image_to_window(base->mlx, \
	base->window, base->img_0.img, 0, 0);
	mlx_put_image_to_window(base->mlx, base->window, base->img_p.img, \
	base->img_p.x, base->img_p.y);
}
