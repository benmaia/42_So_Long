/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:02:18 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/14 19:33:11 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Has the update receives the  */
/* key value and updates the    */
/* the position, it also counts */
/* how many time it updates.    */
/* I've set it when it updates  */
/* 9 times it counts as 1 step  */

int	ft_move_counter(t_base *base)
{
	static int	counter;
	static int	steps;

	ft_update_player(base);
	steps = counter;
	if (base->move_counter >= 1)
	{
		base->move_counter = 0;
		counter++;
	}
	if (counter != steps)
		ft_printf("Number of moves: %i\n", counter);
	return (counter);
}

/* Responsible to print */
/* everything in loop   */

void	ft_paint(t_base *base)
{
	char		*s;
	static int	counter;

	map_print(base);
	update_collectible(base);
	update_exit(base);
	update_enemy(base);
	counter = ft_move_counter(base);
	mlx_put_image_to_window(base->mlx, \
	base->window, base->img_p.img, base->img_p.x, base->img_p.y);
	mlx_string_put(base->mlx, base->window, 0, 0, 0x00FFFFFF, \
	"Number of moves ");
	s = ft_itoa(counter);
	mlx_string_put(base->mlx, base->window, 156, 0, 0x00FFFFFF, s);
	free(s);
	s = NULL;
}
