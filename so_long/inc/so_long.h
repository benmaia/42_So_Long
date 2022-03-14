/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:02:53 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/14 21:49:21 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
/*#include "mlx_int.h"*/
# include <fcntl.h>
# include <stdio.h>

typedef enum s_key {
	W = 13,
	S = 1,
	A = 0,
	D = 2,
	ESC = 53
}	t_key;

/*typedef enum s_key {
 	W = 119,
 	S = 115,
 	A = 97,
 	D = 100,
 	ESC = 65307
}	t_key;
*/

typedef struct s_keys {
	int	w;
	int	s;
	int	a;
	int	d;
	int	esc;
}	t_keys;

typedef struct s_imgs {
	void	*img_w[3];
	void	*img_s[3];
	void	*img_d[3];
	void	*img_a[3];
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	int		pace;
	int		nbr;
	int		counter;
	int		x;
	int		y;
}	t_imgs;

typedef struct s_base {
	void	*mlx;
	void	*window;
	char	**map;
	int		win_x;
	int		win_y;
	int		move_counter;
	char	*scream;
	t_imgs	img_0;
	t_imgs	img_1;
	t_imgs	img_p;
	t_imgs	img_c;
	t_imgs	img_e;
	t_imgs	img_x;
	t_keys	keys;
}		t_base;

t_base	*ft_init_struct(void);

void	ft_init_window(t_base *base);

int		ft_key_hook_up(int keycode, t_base *base);

int		ft_key_hook_down(int keycode, t_base *base);

int		ft_hook(t_base *base);

void	ft_update_player(t_base *base);

int		ft_move_counter(t_base *base);

void	ft_paint(t_base *base);

void	ft_init_animations(t_base *base);

void	ft_init_player_animation(t_base *base);

void	ft_map_ini(int argc, char **argv, t_base *base);

int		map_checker(char **map);

int		ft_checker(t_base *base, char **argv);

int		get_fd(char **argv);

char	**read_map(int fd);

int		check_map_close(char **map);

int		check_map_size(t_base *base, char **map);

int		check_map_playble(t_base *base, char **map);

void	map_print(t_base *base);

void	map_start(t_base *base);

void	ft_init_map(t_base *base);

void	ft_init_player(t_base *base);

void	init_keys(t_base *base);

t_base	*ft_init_struct(void);

void	update_collectible(t_base *base);

void	update_exit(t_base *base);

void	exit_s(t_base *base);

int		check_map_position(t_base *base);

void	colider(t_base *base);

void	update_enemy(t_base *base);

int		sound(t_base *base, char *argv);

#endif
