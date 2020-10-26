/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:13:04 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/26 14:43:24 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	ft_get_z(t_map *all)
{
	while (all->file[all->y] != NULL)
	{
		if (!(all->int_arr[all->yy] = (int*)malloc(sizeof(int) * (1000 + 1 + 1))))
				return ;
		while (all->file[all->y][all->x] != '\0')
		{
			all->val = ft_atoi(all->file[all->y]);
			if (all->y == 0)
				all->first_row_num++;
			all->numbers_in_row++;
			all->int_arr[all->yy][all->xx++] = all->val;
			while (all->file[all->y][all->x] != '\0' && all->file[all->y][all->x] != ' ')
				all->x++;
			while (all->file[all->y][all->x] != '\0' && all->file[all->y][all->x] == ' ')
				all->x++;
			all->file[all->y] = all->file[all->y] + all->x;
			all->x = 0;
		}
		if (all->first_row_num != all->numbers_in_row)
			exit(0);
		all->numbers_in_row = 0;
		all->yy++;
		all->x = 0;
		all->xx = 0;
		all->y++;
	}
	all->int_arr[all->yy] = NULL;
}

void	ft_before_get_z(t_map *all)
{
	all->yy = 0;
	all->xx = 0;
	if (!(all->int_arr = (int**)malloc(sizeof(int*) * (500 + 1))))
		return ;
	all->y = 0;
	all->x = 0;
	all->numbers_in_row = 0;
	all->first_row_num = 0;
	while (all->file[all->y][all->x] != '\0' && all->file[all->y][all->x] == ' ')
		all->x++;
	all->file[all->y] = all->file[all->y] + all->x;
	all->x = 0;
}

int		ft_valid_numbers(t_map *all)
{
	all->y = 0;
	all->x = 0;
	while (all->file[all->y] != NULL)
	{
		while (all->file[all->y][all->x] != '\0')
		{
			if ((all->file[all->y][all->x] >= '0' && all->file[all->y][all->x] <= '9') \
			|| all->file[all->y][all->x] == ' ' || all->file[all->y][all->x] == '-')
				all->x++;
			else
				return (0);
		}
		all->y++;
		all->x = 0;
	}
	return (1);
}

int		ft_valid_file(t_map *all)
{
	if (ft_valid_numbers(all) != 0)
	{
		ft_before_get_z(all);
		ft_get_z(all);
		return (1);
	}
	return (0);
}
