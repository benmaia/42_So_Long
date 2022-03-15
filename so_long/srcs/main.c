/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:39:19 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/15 15:45:39 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Close the window on the X  */
/* and call the exit function */

int	close_x_button(t_base *base)
{
	mlx_destroy_window(base->mlx, base->window);
	exit(EXIT_SUCCESS);
}

/* Runs the program */

int	main(int argc, char **argv)
{
	t_base	*base;

	if (argc != 2)
	{
		ft_printf("Must call a .ber as a second argument");
		exit(EXIT_SUCCESS);
	}
	base = ft_init_struct();
	if (!ft_checker(base, argv))
		exit(EXIT_SUCCESS);
	ft_init_window(base);
	mlx_hook(base->window, 17, 1L << 2, &close_x_button, base);
	mlx_hook(base->window, 2, 1, ft_key_hook_down, base);
	mlx_hook(base->window, 3, 1, ft_key_hook_up, base);
	mlx_loop_hook(base->mlx, ft_hook, base);
	mlx_loop(base->mlx);
	exit_s(base);
}
