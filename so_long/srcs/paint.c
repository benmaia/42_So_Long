/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:02:18 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/12 14:45:41 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Has the update receives the  */
/* key value and updates the    */
/* the position, it also counts */
/* how many time it updates.    */
/* I've set it when it updates  */
/* 9 times it counts as 1 step  */

void	ft_move_counter(t_base *base)
{
	static int	counter;
	static int	steps;

	ft_update_player(base);
	steps = counter;
	if (base->move_counter >= 2)
	{
		base->move_counter = 0;
		counter++;
	}
	if (counter == steps)
		return ;
	ft_printf("Number of moves: %i\n", counter);
}

/* Responsible to print */
/* everything in loop   */

void	ft_paint(t_base *base)
{
	map_print(base);
	update_collectible(base);
	update_exit(base);
	mlx_put_image_to_window(base->mlx, \
	base->window, base->img_p.img, base->img_p.x, base->img_p.y);
}
