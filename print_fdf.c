/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:12:04 by ehelmine          #+#    #+#             */
/*   Updated: 2020/12/08 16:56:39 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	abs_val(float x)
{
	if (x < 0)
		return (x * -1);
	else
		return (x);
}

void	ft_dda(t_map *all)
{
	float x;
	float y;
	float next_x;
	float next_y;

	x = all->x;
	y = all->y;
	next_x = all->next_x;
	next_y = all->next_y;
	all->dx = next_x - x;
	all->dy = next_y - y;
	if (abs_val(all->dx) >= abs_val(all->dy))
		all->slope = abs_val(all->dx);
	else
		all->slope = abs_val(all->dy);
	all->dx = all->dx / all->slope;
	all->dy = all->dy / all->slope;
}

void	ft_print_base_vertical(t_map *all)
{
	while (all->columns < all->first_row_num)
	{
		while (all->yy < all->rows - 1)
		{
			if (all->x > SIZE - 1 || all->y > SIZE - 1)
				break ;
			while (all->y < all->next_y && all->y < SIZE)
			{
				if (all->x > 0 && all->y > 0)
					all->pic[(int)all->x + (all->size_l * (int)all->y)] = \
					all->color;
				all->y++;
			}
			all->next_y = all->y + all->box;
			all->yy++;
		}
		all->yy = 0;
		all->columns++;
		all->y = 0 + all->change_y;
		all->x = all->x + all->box;
		all->next_y = all->y + all->box;
	}
}

void	ft_print_base_horizontal(t_map *all)
{
	while (all->yy < all->rows)
	{
		while (all->columns < all->first_row_num - 1)
		{
			if (all->y > SIZE - 1 || all->x > SIZE - 1)
				break ;
			while (all->x < all->next_x && all->x < SIZE)
			{
				if (all->x > 0 && all->y > 0)
					all->pic[(int)all->x + (all->size_l * (int)all->y)] = \
					all->color;
				all->x++;
			}
			all->columns++;
			all->next_x = all->x + all->box;
		}
		if (all->yy == all->rows - 1 && all->y < SIZE && all->x < SIZE)
			all->pic[(int)all->x + (all->size_l * (int)all->y)] = all->color;
		all->columns = 0;
		all->yy++;
		all->x = 0 + all->change_x;
		all->y = all->y + all->box;
		all->next_x = all->x + all->box;
	}
}
