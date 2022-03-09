/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:09:05 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/09 00:53:56 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Init the S frames to animation */
/* Puts the image to the struct   */

void	ft_init_player_front(t_base *base)
{
	base->img_p.img_s[0] = mlx_xpm_file_to_image(base->mlx, \
	"front.xpm", &base->img_p.width, &base->img_p.height);
	base->img_p.img_s[1] = mlx_xpm_file_to_image(base->mlx, \
	"front2.xpm", &base->img_p.width, &base->img_p.height);
	base->img_p.img_s[2] = mlx_xpm_file_to_image(base->mlx, \
	"front3.xpm", &base->img_p.width, &base->img_p.height);
}

/* Init the A frames to animation */
/* Puts the image to the struct   */

void	ft_init_player_left(t_base *base)
{
	base->img_p.img_a[0] = mlx_xpm_file_to_image(base->mlx, \
	"left.xpm", &base->img_p.width, &base->img_p.height);
	base->img_p.img_a[1] = mlx_xpm_file_to_image(base->mlx, \
	"left2.xpm", &base->img_p.width, &base->img_p.height);
	base->img_p.img_a[2] = mlx_xpm_file_to_image(base->mlx, \
	"left3.xpm", &base->img_p.width, &base->img_p.height);
}

/* Init the D frames to animation */
/* Puts the image to the struct   */

void	ft_init_player_right(t_base *base)
{
	base->img_p.img_d[0] = mlx_xpm_file_to_image(base->mlx, \
	"right.xpm", &base->img_p.width, &base->img_p.height);
	base->img_p.img_d[1] = mlx_xpm_file_to_image(base->mlx, \
	"right2.xpm", &base->img_p.width, &base->img_p.height);
	base->img_p.img_d[2] = mlx_xpm_file_to_image(base->mlx, \
	"right3.xpm", &base->img_p.width, &base->img_p.height);
}

/* Init the W frames to animation */
/* Puts the image to the struct   */

void	ft_init_player_back(t_base *base)
{
	base->img_p.img_w[0] = mlx_xpm_file_to_image(base->mlx, \
	"back.xpm", &base->img_p.width, &base->img_p.height);
	base->img_p.img_w[1] = mlx_xpm_file_to_image(base->mlx, \
	"back2.xpm", &base->img_p.width, &base->img_p.height);
	base->img_p.img_w[2] = mlx_xpm_file_to_image(base->mlx, \
	"back3.xpm", &base->img_p.width, &base->img_p.height);
}

/* Init the walking frames to animation */
/* of the player character              */

void	ft_init_player_animation(t_base *base)
{
	ft_init_player_front(base);
	ft_init_player_left(base);
	ft_init_player_right(base);
	ft_init_player_back(base);
}
