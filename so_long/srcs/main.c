/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:39:19 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/08 19:23:30 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(void)
{
	t_base	*base;

	base = ft_init_struct();
	ft_init_window(base);
	mlx_hook(base->window, 2, 1, ft_key_hook_down, base);
	mlx_hook(base->window, 3, 1, ft_key_hook_up, base);
	mlx_loop_hook(base->mlx, ft_hook, base);
	mlx_loop(base->mlx);
	free(base);
}
