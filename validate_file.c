/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:13:04 by ehelmine          #+#    #+#             */
/*   Updated: 2020/11/06 11:21:14 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	ft_get_z_2(int *str, char *ptr, t_map *all)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (ptr[x] != '\0')
	{
		while (ptr[x] == ' ' && ptr[x] != '\0')
			x++;
		ptr = ptr + x;
		x = 0;
		str[y] = ft_atoi(ptr);
		all->numbers_in_row++;
		y++;
		while (ptr[x] != ' ' && ptr[x] != '\0')
			x++;
		ptr = ptr + x;
		x = 0;
		if (ptr[x] == ' ' && ptr[x + 1] == '\0')
			break ;
	}
	if (all->numbers_in_row != all->first_row_num)
		exit(0);
	all->numbers_in_row = 0;
}

void	ft_get_z(t_map *all)
{
	while (all->file[(int)all->y][(int)all->x] != '\0')
	{
		if (all->file[(int)all->y][(int)all->x] == ' ' && \
		all->file[(int)all->y][(int)all->x - 1] != ' ' && \
		all->file[(int)all->y][(int)all->x + 1] != '\0')
			all->first_row_num++;
		all->x++;
	}
	all->first_row_num += 1;
	all->x = 0;
	all->y = 0;
	while (all->file[(int)all->y] != NULL)
	{
		if (!(all->int_arr[all->yy] = (int*)malloc(sizeof(int) * (50000))))
			return ;
		ft_get_z_2(all->int_arr[all->yy], all->file[(int)all->y], all);
		all->yy++;
		all->y++;
	}
	all->int_arr[all->yy] = NULL;
}

void	ft_before_get_z(t_map *all)
{
	all->yy = 0;
	all->xx = 0;
	if (!(all->int_arr = (int**)malloc(sizeof(int*) * (50000 + 1))))
		return ;
	all->y = 0;
	all->x = 0;
	all->numbers_in_row = 0;
	all->first_row_num = 0;
	while (all->file[(int)all->y][(int)all->x] != '\0' && \
	all->file[(int)all->y][(int)all->x] == ' ')
		all->x++;
	all->file[(int)all->y] = all->file[(int)all->y] + (int)all->x;
	all->x = 0;
}

int		ft_valid_numbers(t_map *all)
{
	all->y = 0;
	all->x = 0;
	while (all->file[(int)all->y] != NULL)
	{
		while (all->file[(int)all->y][(int)all->x] != '\0')
		{
			if ((all->file[(int)all->y][(int)all->x] >= '0' && \
			all->file[(int)all->y][(int)all->x] <= '9') \
			|| all->file[(int)all->y][(int)all->x] == ' ' \
			|| all->file[(int)all->y][(int)all->x] == '-')
				all->x++;
			else
				return (0);
		}
		all->y++;
		all->x = 0;
	}
	return (1);
}

/*
**	Check if it is a valid file, then declare some variables, and then get all z
**	coordinates to int array. Then declare here some other things before
**	going back to create the image.
*/

int		ft_valid_file(t_map *all)
{
	if (ft_valid_numbers(all) != 0)
	{
		ft_before_get_z(all);
		ft_get_z(all);
		if (all->first_row_num > 50)
			all->box_val = 8;
		else
			all->box_val = 20;
		all->color = GREEN;
		all->chara = 'p';
		all->change_z = 0;
		return (1);
	}
	return (0);
}
