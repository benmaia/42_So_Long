/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:02:53 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/05 19:11:54 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define IMG_WIDTH 2560
# define IMG_HEIGHT 1440

typedef enum key {
	W = 13,
	S = 1,
	A = 0,
	D = 2,
	ESC = 53
}	t_key;

typedef struct s_img {
    void	*img;
    char	*address;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
	int		height;
	int		width;
}       t_img;

typedef struct s_structer {
	void	*mlx;
	void	*window;
	char	**map;
	int		win_x;
	int		win_y;
	int		move_counter;
	int		map_x;
	int		map_y;
	int		x;
	int		y;
	int		px;
	int		py;
	int		ex;
	int		ey;
	t_img	img_0;
	t_img	img_1;
	t_img	img_p;
	t_img	img_c;
	t_img	img_e;
	
}		t_structer;

// typedef struct s_img {
//     void	*img;
//     char	*address;
//     int		bits_per_pixel;
//     int		line_length;
//     int		endian;
// 	int		height;
// 	int		width;
// }       t_img;

// typedef struct s_char {
//     void    *img;
//     char    *address;
//     int     bits_per_pixel;
//     int     line_length;
//     int     endian;
// }       t_char;

int main();

t_structer *ft_init_struct(void);

void	ft_init_window(t_structer *structer);

//

#endif
