/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:13:04 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/22 12:24:32 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	ft_get_z()
{
	while (t_map.file[t_map.y] != NULL)
	{
		if (!(t_map.int_arr[t_map.yy] = (int*)malloc(sizeof(int) * (1000 + 1 + 1))))
				return ;
		while (t_map.file[t_map.y][t_map.x] != '\0')
		{
			t_map.val = ft_atoi(t_map.file[t_map.y]);
			if (t_map.y == 0)
				t_map.first_row_num++;
			t_map.numbers_in_row++;
			t_map.int_arr[t_map.yy][t_map.xx++] = t_map.val;
			while (t_map.file[t_map.y][t_map.x] != '\0' && t_map.file[t_map.y][t_map.x] != ' ')
				t_map.x++;
			while (t_map.file[t_map.y][t_map.x] != '\0' && t_map.file[t_map.y][t_map.x] == ' ')
				t_map.x++;
			t_map.file[t_map.y] = t_map.file[t_map.y] + t_map.x;
			t_map.x = 0;
		}
		if (t_map.first_row_num != t_map.numbers_in_row)
			exit(0);
		t_map.numbers_in_row = 0;
		t_map.yy++;
		t_map.x = 0;
		t_map.xx = 0;
		t_map.y++;
	}
	t_map.int_arr[t_map.yy] = NULL;
}

void	ft_before_get_z()
{
	t_map.yy = 0;
	t_map.xx = 0;
	if (!(t_map.int_arr = (int**)malloc(sizeof(int*) * (500 + 1))))
		return ;
	t_map.y = 0;
	t_map.x = 0;
	t_map.numbers_in_row = 0;
	t_map.first_row_num = 0;
	while (t_map.file[t_map.y][t_map.x] != '\0' && t_map.file[t_map.y][t_map.x] == ' ')
		t_map.x++;
	t_map.file[t_map.y] = t_map.file[t_map.y] + t_map.x;
	t_map.x = 0;
}

int		ft_valid_numbers()
{
	t_map.y = 0;
	t_map.x = 0;
	while (t_map.file[t_map.y] != NULL)
	{
		while (t_map.file[t_map.y][t_map.x] != '\0')
		{
			if ((t_map.file[t_map.y][t_map.x] >= '0' && t_map.file[t_map.y][t_map.x] <= '9') \
			|| t_map.file[t_map.y][t_map.x] == ' ' || t_map.file[t_map.y][t_map.x] == '-')
				t_map.x++;
			else
				return (0);
		}
		t_map.y++;
		t_map.x = 0;
	}
	return (1);
}

int		ft_valid_file()
{
	if (ft_valid_numbers() != 0)
	{
		ft_before_get_z();
		ft_get_z();
		return (1);
	}
	return (0);
}
