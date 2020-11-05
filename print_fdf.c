/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:12:04 by ehelmine          #+#    #+#             */
/*   Updated: 2020/11/05 17:55:08 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

float		abs_val(float x)
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
	printf("all->slope %f\n", all->slope);
	all->dx = all->dx / all->slope;
	all->dy = all->dy / all->slope;
}

void	ft_isometric(t_map *all, float val_1, float val_2)
{
	int org_x;
	int org_y;

	org_x = all->x;
	org_y = all->y;
	all->x = (org_x - org_y) * cos(0.523599);
	all->y = -val_1 + (org_x + org_y) * sin(0.523599);
	org_x = all->next_x;
	all->next_x = (org_x - org_y) * cos(0.523599);
	all->next_y = -val_2 + (org_x + org_y) * sin(0.523599);
}

void	ft_print_isometric(t_map *all)
{
	float val_1;
	float val_2;
	int xx;
	int yy;
	float i;

	all->columns = all->first_row_num - 1;
	all->yy = all->rows;
	xx = 0;
	yy = 0;
	while (all->yy > 0)
	{
		while (all->columns > 0)
		{
			val_1 = all->int_arr[yy][xx++];
			val_2 = all->int_arr[yy][xx];
			ft_isometric(all, val_1, val_2);
			ft_dda(all);
			i = 0;
			while (i < all->slope)
			{
				all->pic[(int)all->x + (all->size_l * (int)all->y) + 282500] = all->color;
				all->y = all->y + all->dy;
				all->x = all->x + all->dx;
				i++;
			}
			all->y = 0 + all->change_y;
//			all->x = 0 + all->change_x + all->box;
			all->next_x = all->x + all->box;
			all->next_y = all->y + all->box;
			all->columns--;
		}
		all->yy--;
		yy++;
		xx = 0;
		all->columns = all->first_row_num - 1;
		all->y = 0 + all->change_y + all->box;
		all->x = 0 + all->change_x;
		all->next_x = all->x + all->box;
		all->next_y = all->y;
	}
}

void	ft_print_base_vertical(t_map *all)
{
	all->columns = all->first_row_num;
	all->yy = all->rows - 1;
	while (all->columns > 0)
	{
		while (all->yy > 0)
		{
			if (all->next_y > 699 || all->x > 699 || all->y > 699)
				break ;
			while (all->y < all->next_y && all->y < 700)
				all->pic[(int)all->x + (all->size_l * (int)all->y++) + 282500] = all->color;
			all->next_y = all->y + all->box;
			all->yy--;
		}
		all->yy = all->rows - 1;
		all->columns--;
		all->y = 0 + all->change_y;
		all->x = all->x + all->box;
		all->next_y = all->y + all->box;
	}
}

void	ft_print_base_horizontal(t_map *all)
{
	printf("how many columns %i\n", all->first_row_num);
	printf("how many rows %i\n", all->rows);
	all->columns = all->first_row_num - 1;
	all->yy = all->rows;
	while (all->yy > 0)
	{
		while (all->columns > 0)
		{
			if (all->next_x > 999 || all->y > 699 || all->x > 999)
				break ;
			while (all->x < all->next_x && all->x < 1000)
				all->pic[(int)all->x++ + (all->size_l * (int)all->y) + 282500] = all->color;
			all->columns--;
			all->next_x = all->x + all->box;
		}
		all->columns = all->first_row_num - 1;
		all->yy--;
		all->x = 0 + all->change_x;
		all->y = all->y + all->box;
		all->next_x = all->x + all->box;
	}
}
