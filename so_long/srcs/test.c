/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:39:19 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/03 19:46:21 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int main()
{
	void	*mlx;
	void	*window;
	t_map	imgs;
	t_char	img2;
	int		x;
	int		y;
	int		x1;
	int		y1;

	
	mlx = mlx_init();
	window = mlx_new_window(mlx, 2000, 1500, "So Long");
	imgs.img = mlx_xpm_file_to_image(mlx, "oooo.xpm", &x, &y);
	img2.img = mlx_xpm_file_to_image(mlx, "111.xpm", &x, &y);
	imgs.address = mlx_get_data_addr(imgs.img, &imgs.bits_per_pixel, &imgs.line_length, &imgs.endian);
	img2.address = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length, &img2.endian);
	//mlx_put_image_to_window(mlx, window, imgs.img, 0, 0);
	x1 = 0;
	y1 = 0;
	while (y1 < 1)
	{
		x1 = 0;
		while (x1 < 1)
		{
			mlx_put_image_to_window(mlx, window, imgs.img, 0, 0);
			mlx_put_image_to_window(mlx, window, img2.img, x1, y1);
			x1++;
		}
		y1++;
	}
	//mlx_put_image_to_window(mlx, window, imgs.img, 0, 0);
	//img2.img = mlx_xpm_file_to_image(mlx, "111.xpm", &x, &y);
	//mlx_put_image_to_window(mlx, window, img2.img, 100, 100);
	mlx_destroy_image(mlx, img2.img);
	mlx_loop(mlx);
}
