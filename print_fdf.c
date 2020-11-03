/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:12:04 by ehelmine          #+#    #+#             */
/*   Updated: 2020/11/03 09:36:02 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_isometric_x(t_map *all)
{
	float prev_x;
	float org_x;
	float org_y;

	org_x = all->x;
	org_y = all->y;
	all->x = (org_x - org_y) * cos(0.8);
	prev_x = all->next_x;
	all->next_x = (prev_x - org_y) * cos(0.8);
	all->y = -(1) + ((org_x + org_y) * sin(0.5));
}

void	ft_isometric_y(t_map *all)
{
	float prev_x;
	float prev_y;
	float org_x;
	float org_y;
	int yy;
	int xx;
	int val;

	val = 1;
	yy = 0;
	xx = 0;
	org_x = all->x;
	org_y = all->y;
	prev_x = all->x;
	prev_y = all->y;
	all->y = -(val) + ((prev_x + prev_y) * sin(0.5));
	prev_y = all->next_y;
	all->next_y = -(3) + ((prev_x + prev_y) * sin(0.5));
//	all->x = (org_x - org_y) * cos(0.8);
}

void	ft_isometric_v(t_map *all, int val_1, int val_2, int point)
{
	float org_x;
	float org_y;
	int yy;
	int xx;

	yy = 0;
	xx = 0;
	org_x = all->x;
	org_y = all->y;
	if (point == 1)
	{
		all->y = -(val_1) + ((org_x + org_y) * sin(0.5));
		all->x = (org_x - org_y) * cos(0.8);
		org_y = all->next_y;
		all->next_y = -(val_2) + ((org_x + org_y) * sin(0.5));
	}
	else
	{
		all->y = -(val_2) + ((org_x + org_y) * sin(0.5));
		all->x = (org_x - org_y) * cos(0.8);
		org_y = all->next_y;
		all->next_y = -(val_1) + ((org_x + org_y) * sin(0.5));
	}

}

void	ft_print_isometric_v(t_map *all)
{
	int org_y;
	int dob;
	int yy;
	int xx;
	int val_1;
	int val_2;

	dob = 2;
	org_y = all->y;
	all->columns = all->first_row_num;
	all->yy = all->rows - 1;
	yy = 0;
	xx = 0;
	while (all->columns > 0)
	{
		while (all->yy > 0)
		{
			val_1 = all->int_arr[yy][xx++];
			val_2 = all->int_arr[yy][xx];
			ft_isometric_v(all, val_1, val_2, xx);
			while (all->y < all->next_y)
				all->pic[all->x++ + (all->size_l * all->y++)] = all->color;
			all->yy--;
			all->y = org_y + (all->box * dob);
			all->next_y = org_y + (all->box * dob++);
		}
//		all->int_arr[yy++][xx];
		yy++;
		xx = 0;
		all->x = 0 + all->change_x + all->box;
		all->columns--;
		all->y = 0 + all->change_y;
		all->next_y = all->y + all->box;
		all->yy = all->rows - 1;
		dob = 2;
		org_y = all->y;
	}
}

void	ft_print_base_vertical(t_map *all)
{
	all->next_y = all->y + all->box;
	all->columns = all->first_row_num;
	all->yy = all->rows - 1;
//	ft_isometric_y(all);
	while (all->columns > 0)
	{
		while (all->yy > 0)
		{
			if (all->next_y > 699 || all->x > 999 || all->y > 699)
				break ;
			while (all->y < all->next_y && all->y < 700)
				all->pic[all->x + (all->size_l * all->y++)] = all->color;
			all->next_y = all->y + all->box;
//			ft_isometric_y(all);
			all->yy--;
		}
		all->yy = all->rows - 1;
		all->columns--;
		printf("\nlast y %i\n", all->y);
		all->y = 0 + all->change_y;
		all->x = all->x + all->box;
		all->next_y = all->y + all->box;
//		ft_isometric_y(all);
	}
}

void	ft_print_base_horizontal(t_map *all)
{
	printf("how many columns %i\n", all->first_row_num);
	printf("how many rows %i\n", all->rows);
	all->next_x = all->x + all->box;
	all->columns = all->first_row_num - 1;
	all->yy = all->rows;
//	ft_isometric_x(all);
	while (all->yy > 0)
	{
		while (all->columns > 0)
		{
			if (all->next_x > 999 || all->y > 699 || all->x > 999)
				break ;
			while (all->x < all->next_x && all->x < 1000)
				all->pic[all->x++ + (all->size_l * all->y)] = all->color;
			all->columns--;
			all->next_x = all->x + all->box;
		}
		all->columns = all->first_row_num - 1;
		all->yy--;
//		printf("\nlast x %i\n", all->x);
		all->x = 0 + all->change_x;
		all->y = all->y + all->box;
		all->next_x = all->x + all->box;
//		ft_isometric_x(all);
	}
	printf("\nlast place %i\n", all->x + (all->size_l * all->y));
}
