/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:39:19 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/04 22:42:00 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// static int	finish(t_structer *env)
// {
// 	//free_struct(env);
// 	mlx_destroy_image(env->mlx, env->img_1.img);
// 	mlx_destroy_image(env->mlx, env->img_0.img);
// 	mlx_destroy_image(env->mlx, env->img_p.img);
// 	//mlx_destroy_image(env->mlx, env->i_e.img);
// 	//mlx_destroy_image(env->mlx, env->i_c.img);
// 	mlx_destroy_window(env->mlx, env->window);
// 	//exit(0);
// 	return (1);
// }

int loop(int keycode, t_structer *structer)
{
	(void) keycode;
	(void) structer;
	int x = 0;
	int y = 0;
	
	while (++y < 1000)
	{
		x = 0;
		while (++x < 1000)
		{
			mlx_put_image_to_window(structer->mlx, structer-> window, structer->img_0.img, structer->win_x, structer->win_y);
			mlx_put_image_to_window(structer->mlx, structer-> window, structer->img_p.img, x, y);
			x += 100;
		}
		y += 100;
	}
	return (1);
}

int	key_hook(int keycode, t_structer *structer)
{
	(void) keycode;
	(void) structer;
	int x = 0;
	int y = 0;

	//printf("Hello from key_hook!\n");
	// mlx_destroy_image(structer->mlx, structer->img_p.img);
	// mlx_destroy_image(structer->mlx, structer->img_0.img);
	// mlx_destroy_window(structer->mlx, structer->window);
	// structer->img_p.img = mlx_xpm_file_to_image(structer->mlx, "char.xpm", &structer->img_p.width, &structer->img_p.height);
	// mlx_put_image_to_window(structer->mlx, structer-> window, structer->img_p.img, x, y);
	//mlx_clear_window(structer->mlx, structer->window);
	//mlx_clear_window(structer->mlx, structer->window);
	printf("ok %i %i\n", x, y);
	// while (++y < 1000)
	// {
	// 	x = 0;
	// 	while (++x < 1000)
	// 	{
	// 		// mlx_put_image_to_window(structer->mlx, structer-> window, structer->img_0.img, structer->win_x, structer->win_y);
	// 		mlx_put_image_to_window(structer->mlx, structer-> window, structer->img_p.img, x, y);
	// 		x += 100;
	// 	}
	// 	y += 100;
	//}
	mlx_key_hook(structer->window, loop, structer);
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
