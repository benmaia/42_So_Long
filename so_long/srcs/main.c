/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:39:19 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/05 19:28:26 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_structer *structer)
{
	(void) keycode;
	(void) structer;
	static int x = 0;
	static int y = 0;

	printf("ok %i %i\n", x, y);
	if (keycode == W)
		y -= 100;
	if (keycode == S)
		y += 100;
	if (keycode == D)
		x += 100;
	if (keycode == A)
		x -= 100;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	mlx_put_image_to_window(structer->mlx, structer-> window, \
	structer->img_0.img, 0, 0);
	mlx_put_image_to_window(structer->mlx, structer-> window, \
	structer->img_p.img, x, y);

	return (1);
}

int main()
{
	t_structer	*structer;
	
	structer = ft_init_struct();
	ft_init_window(structer);
	mlx_key_hook(structer->window, key_hook, structer);
	mlx_loop(structer->mlx);
	free(structer);
}