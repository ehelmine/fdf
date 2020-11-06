/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_and_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:15:07 by ehelmine          #+#    #+#             */
/*   Updated: 2020/11/06 16:11:38 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_exit(void)
{
	exit(0);
}

void	ft_color(t_map *all)
{
	if (all->color == GREEN)
		all->color = BLUE;
	else if (all->color == BLUE)
		all->color = RED;
	else if (all->color == RED)
		all->color = YELLOW;
	else if (all->color == YELLOW)
		all->color = GREEN;
}

void	ft_more_keys(int key, t_map *all)
{
	if (key == MOVE_LEFT || key == XK_LEFT)
		all->change_x -= 10;
	if (key == MOVE_RIGHT || key == XK_RIGHT)
		all->change_x += 10;
	if (key == MOVE_UP || key == XK_UP)
		all->change_y -= 10;
	if (key == MOVE_DOWN || key == XK_DOWN)
		all->change_y += 10;
	if (key == PROJECTIONS)
	{
		all->chara = 'i';
		if (all->angle == 0.523599)
			all->angle = 0.7862975;
		else if (all->angle == 0.7862975)
			all->angle = 0.523599;
	}
	if (key == PARALLEL)
		all->chara = 'p';
	ft_memset(all->pic, 0, all->size_l);
	ft_image_control(all);
	ft_call_draws(all);
}

int		ft_choose_key(int key, t_map *all)
{
	ft_putnbr(key);
	if (key == ESC_KEY || key == XK_ESCAPE)
		exit(0);
	if (key == MOVE_LEFT || key == MOVE_RIGHT ||
		key == MOVE_UP || key == MOVE_DOWN ||
		key == PROJECTIONS || key == PARALLEL)
		ft_more_keys(key, all);
	if (key == ZOOM_IN || key == 34)
	{
		all->box_val += 1;
		all->change_z += 1;
	}
	if ((key == ZOOM_OUT || key == 31) && all->box > 2)
	{
		all->box_val -= 1;
		all->change_z -= 1;
	}
	if (key == 99 || key == 8)
		ft_color(all);
	if (key == 24)
		all->change_z += 10;
	if (key == 27)
		all->change_z -= 10;
	ft_memset(all->pic, 0, all->size_l);
	ft_image_control(all);
	ft_call_draws(all);
	ft_putchar(' ');
	return (1);
}
