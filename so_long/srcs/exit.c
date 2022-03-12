/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:46:51 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/12 15:06:37 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	free_map(t_base *base)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (base->map[++i])
		free(base->map[i]);
	free(base->map);
}

void	free_player(t_base *base)
{
	free(base->img_p.img);
}

void	free_collectible(t_base *base)
{
	free(base->img_c.img);
}

void	free_exit(t_base *base)
{
	free(base->img_e.img);
}

void	exit_s(t_base *base)
{
	free_map(base);
	free_player(base);
	free_collectible(base);
	free(base);
	exit(EXIT_SUCCESS);
}