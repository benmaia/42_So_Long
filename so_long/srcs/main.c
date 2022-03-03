/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:21:16 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/03 14:40:10 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"
/*
int	deal_key(int key, void *param)
{
	ft_putchar_fd('X', 1);
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	(void)key;
	(void)param;
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int main()
{
	void *mlx;
	void *win;
	void	*img;
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer;
	int x;
	int y;
	//int pixel;
	int color = 0xABCDEF;
		
	x = -1;
	y = -1;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "mlx 42");
	img = mlx_new_image(mlx, 1000, 1000);
	buffer = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
	while (++y < 800)
	{
		while (++x < 1000)
		{
			int pixel = (y * line_bytes) + (x * 4);

			if (endian == 1)        // Most significant (Alpha) byte first
    		{
        		buffer[pixel + 0] = (color >> 24);
        		buffer[pixel + 1] = (color >> 16) & 0xFF;
        		buffer[pixel + 2] = (color >> 8) & 0xFF;
        		buffer[pixel + 3] = (color) & 0xFF;
   			}
    		else if (endian == 0)   // Least significant (Blue) byte first
    		{
       			 buffer[pixel + 0] = (color) & 0xFF;
       			 buffer[pixel + 1] = (color >> 8) & 0xFF;
       			 buffer[pixel + 2] = (color >> 16) & 0xFF;
        		buffer[pixel + 3] = (color >> 24);
    		}
		}
		x = -1;
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	//mlx_string_put(mlx, win, 500, 500, create_trgb(0, 255, 0 , 0), "ola tudo bem");
	mlx_key_hook(win, deal_key, (void *)0);
	mlx_loop(mlx);*/
}
