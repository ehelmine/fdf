/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_and_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:15:07 by ehelmine          #+#    #+#             */
/*   Updated: 2020/12/09 19:41:55 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (key == XK_LEFT)
		all->change_x -= 10;
	if (key == XK_RIGHT)
		all->change_x += 10;
	if (key == XK_UP)
		all->change_y -= 10;
	if (key == XK_DOWN)
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
}

int		ft_choose_key(int key, t_map *all)
{
	if (key == XK_ESCAPE)
		exit(0);
	if (key == PROJECTIONS || key == PARALLEL || key == XK_DOWN ||
		key == XK_UP || key == XK_LEFT || key == XK_RIGHT)
		ft_more_keys(key, all);
	if (key == ZOOM_IN)
	{
		all->box_val += 1;
		all->change_z += 1;
	}
	if ((key == ZOOM_OUT) && all->box > 4)
	{
		all->box_val -= 1;
		all->change_z -= 1;
	}
	if (key == CHANGE_COLOR)
		ft_color(all);
	if (key == MORE_HIGH && all->chara == 'i')
		all->amp += 0.05;
	if (key == LESS_HIGH && all->chara == 'i')
		all->amp -= 0.05;
	mlx_destroy_image(all->mlx_ptr, all->image);
	ft_image_control(all);
	ft_call_draws(all);
	return (1);
}
