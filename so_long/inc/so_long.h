/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paijavai <paijavai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:02:53 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/08 14:44:17 by paijavai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
//# include "../libs/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

// typedef enum key {
// 	W = 13,
// 	S = 1,
// 	A = 0,
// 	D = 2,
// 	ESC = 53
// }	t_key;

typedef enum key {
	W = 119,
	S = 115,
	A = 97,
	D = 100,
	ESC = 65307
}	t_key;

typedef struct keys {
	int	w;
	int	s;
	int	a;
	int	d;
	int	esc;
}	t_keys;

typedef struct s_img {
	void	*img_w;
	void	*img_s;
	void	*img_d;
	void	*img_a;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	int		pace;
	int		x;
	int		y;
}	t_img;

typedef struct s_base {
	void	*mlx;
	void	*window;
	char	**map;
	int		win_x;
	int		win_y;
	int		move_counter;
	t_img	img_0;
	t_img	img_1;
	t_img	img_p;
	t_img	img_c;
	t_img	img_e;
	t_keys	keys;
}		t_base;

int		main(void);

t_base	*ft_init_struct(void);

void	ft_init_window(t_base *base);

int		ft_key_hook_up(int keycode, t_base *base);

int		ft_key_hook_down(int keycode, t_base *base);

int		ft_hook(t_base *base);

int		ft_update(t_base *base, int *temp);

void	ft_move_counter(t_base *base);

void	ft_paint(t_base *base);
//

#endif
