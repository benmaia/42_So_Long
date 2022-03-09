/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:31:10 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/03/09 00:25:31 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Update the W key, chooses */
/* what frame to be painted  */
/* and counts the number of  */
/* movements                 */

void	ft_update_up(t_base *base)
{
	static int	w;

	if (base->keys.w && !base->keys.s)
	{
		base->img_p.img = base->img_p.img_w[w];
		base->img_p.y -= base->img_p.pace;
		base->move_counter += 1;
		if (w < 2)
			w += 1;
		else
			w = 0;
	}
}

/* Update the S key, chooses */
/* what frame to be painted  */
/* and counts the number of  */
/* movements                 */

void	ft_update_down(t_base *base)
{
	static int	s;

	if (!base->keys.w && base->keys.s)
	{
		base->img_p.img = base->img_p.img_s[s];
		base->img_p.y += base->img_p.pace;
		base->move_counter += 1;
		if (s < 2)
			s += 1;
		else
			s = 0;
	}
}

/* Update the A key, chooses */
/* what frame to be painted  */
/* and counts the number of  */
/* movements                 */

void	ft_update_left(t_base *base)
{
	static int	a;

	if (base->keys.a && !base->keys.d)
	{
		base->img_p.img = base->img_p.img_a[a];
		base->img_p.x -= base->img_p.pace;
		base->move_counter += 1;
		if (a < 2)
			a += 1;
		else
			a = 0;
	}
}

/* Update the D key, chooses */
/* what frame to be painted  */
/* and counts the number of  */
/* movements                 */

void	ft_update_right(t_base *base)
{
	static int	d;

	if (!base->keys.a && base->keys.d)
	{
		base->img_p.img = base->img_p.img_d[d];
		base->img_p.x += base->img_p.pace;
		base->move_counter += 1;
		if (d < 2)
			d += 1;
		else
			d = 0;
	}
}

/* Depending on the key value    */
/* and the pace, updates his     */
/* position, ready to be printed */
/* and passes the right image to */
/* be printed so the paint func  */
/* just prints the right sprite  */

void	ft_update(t_base *base)
{
	static int	pace;

	if (pace++ < 3)
		return ;
	pace = 0;
	ft_update_up(base);
	ft_update_down(base);
	ft_update_left(base);
	ft_update_right(base);
}
