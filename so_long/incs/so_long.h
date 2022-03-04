/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:02:53 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/03 23:59:53 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"

typedef struct s_map {
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_map;

typedef struct s_wall {
    void    *img;
    char    *address;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}       t_wall;

typedef struct s_char {
    void    *img;
    char    *address;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}       t_char;

int main();

#endif
