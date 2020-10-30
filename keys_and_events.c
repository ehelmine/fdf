/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_and_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:15:07 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/30 12:16:28 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int		ft_choose_key(int key, t_map *all)
{
	ft_putnbr(key);
	if (key == ZOOM_IN || key == 34)
	{
		ft_memset(all->pic, 0, all->size_l);
		ft_image_control(all);
		all->box_val += 1;
		ft_call_draws(all);
	}
	if ((key == ZOOM_OUT || key == 31) && all->box > 2)
	{
		ft_memset(all->pic, 0, all->size_l);
		ft_image_control(all);
		all->box_val -= 1;
		ft_call_draws(all);
	}
	if (key == ESC_KEY || key == XK_ESCAPE)
	{
	//	system("leaks fdf");
		exit(0);
	}
	if (key == MOVE_LEFT || key == XK_LEFT)
	{
		ft_memset(all->pic, 0, all->size_l);
		ft_image_control(all);
		all->change_x -= 3;
		ft_call_draws(all);
	}
	if (key == MOVE_RIGHT || key == XK_RIGHT)
	{
		ft_memset(all->pic, 0, all->size_l);
		ft_image_control(all);
		all->change_x += 3;
		ft_call_draws(all);
	}
	if (key == MOVE_UP || key == XK_UP)
	{
		ft_memset(all->pic, 0, all->size_l);
		ft_image_control(all);
		all->change_y -= 3;
		ft_call_draws(all);
	}
	if (key == MOVE_DOWN || key == XK_DOWN)
	{
		ft_memset(all->pic, 0, all->size_l);
		ft_image_control(all);
		all->change_y += 3;
		ft_call_draws(all);
	}
	if (key == 99 || key == 8)
	{
		ft_memset(all->pic, 0, all->size_l);
		ft_image_control(all);
		ft_color(all);
		ft_call_draws(all);
	}
	ft_putchar(' ');
	return (1);
}
