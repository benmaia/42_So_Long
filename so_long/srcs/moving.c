/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:38:01 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/07 21:04:24 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_key_hook_up(int keycode, t_base *base)
{
	if (keycode == W)
		base->keys.w = 1;
	if (keycode == S)
		base->keys.s = 1;
	if (keycode == D)
		base->keys.d = 1;
	if (keycode == A)
		base->keys.a = 1;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	return (1);
}

int	ft_key_hook_down(int keycode, t_base *base)
{
	if (keycode == W)
		base->keys.w = 0;
	if (keycode == S)
		base->keys.s = 0;
	if (keycode == D)
		base->keys.d = 0;
	if (keycode == A)
		base->keys.a = 0;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	return (1);
}

int	ft_hook(t_base *base)
{
	ft_move_counter(base);
	ft_paint(base);
	return (1);
}
