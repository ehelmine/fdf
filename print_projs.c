/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_projs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:51:54 by ehelmine          #+#    #+#             */
/*   Updated: 2020/12/07 13:15:01 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_projection_v(t_map *all, float val_1, float val_2)
{
	int org_x;
	int org_y;

	if ((int)val_1 != 0 && all->change_z != 0)
		val_1 = val_1 * all->change_z;
	if ((int)val_2 != 0 && all->change_z != 0)
		val_2 = val_2 * all->change_z;
	org_x = all->x;
	org_y = all->y;
	all->x = (org_x - org_y) * cos(all->angle);
	all->y = -(val_1) + (org_x + org_y) * sin(all->angle);
	org_y = all->next_y;
	all->next_x = (org_x - org_y) * cos(all->angle);
	all->next_y = -(val_2) + (org_x + org_y) * sin(all->angle);
}

void	ft_projection_h(t_map *all, float val_1, float val_2)
{
	int org_x;
	int org_y;

	if ((int)val_1 != 0 && all->change_z != 0)
		val_1 = val_1 * all->change_z;
	if ((int)val_2 != 0 && all->change_z != 0)
		val_2 = val_2 * all->change_z;
	org_x = all->x;
	org_y = all->y;
	all->x = (org_x - org_y) * cos(all->angle);
	all->y = -(val_1) + (org_x + org_y) * sin(all->angle);
	org_x = all->next_x;
	all->next_x = (org_x - org_y) * cos(all->angle);
	all->next_y = -(val_2) + (org_x + org_y) * sin(all->angle);
}

void	ft_print_projection_h(t_map *all)
{
	while (all->yy < all->rows)
	{
		while (all->columns < all->first_row_num - 1)
		{
			all->val_1 = all->int_arr[all->i][all->ii++];
			all->val_2 = all->int_arr[all->i][all->ii];
			ft_projection_h(all, all->val_1, all->val_2);
			ft_dda(all);
			all->i_slope = 0;
			while (all->i_slope < all->slope)
				ft_print_proj_loop(all);
			all->y = 0 + all->change_y + (all->box * all->yy);
			all->x = 0 + all->change_x + (all->box * ++all->columns);
			all->next_x = all->x + all->box;
			all->next_y = all->y;
		}
		all->i++;
		all->ii = 0;
		all->columns = 0;
		all->y = 0 + all->change_y + (all->box * ++all->yy);
		all->x = 0 + all->change_x;
		all->next_x = all->x + all->box;
		all->next_y = all->y;
	}
}

void	ft_print_projection_v(t_map *all)
{
	while (all->columns < all->first_row_num)
	{
		while (all->yy < all->rows - 1)
		{
			all->val_1 = all->int_arr[all->i++][all->ii];
			all->val_2 = all->int_arr[all->i][all->ii];
			ft_projection_v(all, all->val_1, all->val_2);
			ft_dda(all);
			all->i_slope = 0;
			while (all->i_slope < all->slope)
				ft_print_proj_loop(all);
			all->y = 0 + all->change_y + (all->box * ++all->yy);
			all->x = 0 + all->change_x + (all->box * all->columns);
			all->next_x = all->x;
			all->next_y = all->y + all->box;
		}
		all->ii++;
		all->i = 0;
		all->yy = 0;
		all->y = 0 + all->change_y;
		all->x = 0 + all->change_x + (all->box * ++all->columns);
		all->next_x = all->x;
		all->next_y = all->y + all->box;
	}
}
