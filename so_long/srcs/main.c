/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paijavai <paijavai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:39:19 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/06 21:31:09 by paijavai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_structer *structer)
{
	(void) keycode;
	(void) structer;
	static int x = 0;
	static int y = 0;
	static int counter;

	if (keycode != 'w' && keycode != 's' && keycode != 'a' && keycode != 'd' && keycode != '0')
		return (0);
	counter++;
	mlx_put_image_to_window(structer->mlx, structer-> window, \
	structer->img_0.img_d, 0, 0);
	//y += 200;
	if (keycode == 'w')
	{
		y -= 32;
		mlx_put_image_to_window(structer->mlx, structer-> window, \
		structer->img_p.img_u, x, y);
	}
	//	y -= 32;
	if (keycode == 's')
	{
		y += 32;
		mlx_put_image_to_window(structer->mlx, structer-> window, \
		structer->img_p.img_d, x, y);
	}
		//y += 32;
	if (keycode == 'd')
	{
		x += 32;
		mlx_put_image_to_window(structer->mlx, structer-> window, \
		structer->img_p.img_r, x, y);
	}
		//x += 32;
	if (keycode == 'a')
	{
		x -= 32;
		mlx_put_image_to_window(structer->mlx, structer-> window, \
		structer->img_p.img_l, x, y);
	}
		//x -= 32;
	if (keycode == '0')
		exit(EXIT_SUCCESS);
		//return (0);
	
	/*mlx_put_image_to_window(structer->mlx, structer-> window, \
	 structer->img_0.img, 0, 0);
	 mlx_put_image_to_window(structer->mlx, structer-> window, \
	 structer->img_p.img, x, y);*/
	printf("Number of steps: %i\n", counter);
	return (1);
}

int main()
{
	t_structer	*structer;
	
	structer = ft_init_struct();
	ft_init_window(structer);
	//mlx_key_hook(structer->window, key_hook, structer);
	mlx_hook(structer->window, 2, 1L<<0, key_hook, structer);
	mlx_loop(structer->mlx);
	free(structer);
}
