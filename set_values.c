/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:47:45 by ehelmine          #+#    #+#             */
/*   Updated: 2020/12/08 19:13:21 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_values_for_print_h(t_map *all)
{
	all->y = 0 + all->change_y;
	all->x = 0 + all->change_x;
	all->box = all->box_val;
	all->next_x = all->x + all->box;
	all->next_y = all->y;
	all->columns = 0;
	all->yy = 0;
}

void	ft_values_for_print_v(t_map *all)
{
	all->y = 0 + all->change_y;
	all->x = 0 + all->change_x;
	all->box = all->box_val;
	all->next_x = all->x;
	all->next_y = all->y + all->box;
	all->columns = 0;
	all->yy = 0;
}

void	ft_values_for_proj_h(t_map *all)
{
	all->y = 0 + all->change_y;
	all->x = 0 + all->change_x;
	all->box = all->box_val;
	all->next_x = all->x + all->box;
	all->next_y = all->y;
	all->columns = 0;
	all->yy = 0;
	all->i_slope = 0;
	all->i = 0;
	all->ii = 0;
}

void	ft_values_for_proj_v(t_map *all)
{
	all->y = 0 + all->change_y;
	all->x = 0 + all->change_x;
	all->box = all->box_val;
	all->next_x = all->x;
	all->next_y = all->y + all->box;
	all->columns = 0;
	all->yy = 0;
	all->i_slope = 0;
	all->i = 0;
	all->ii = 0;
}
