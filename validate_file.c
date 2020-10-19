/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:13:04 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/19 13:09:38 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	ft_get_z()
{
	int val;
	int yy;
	int xx;

	yy = 0;
	xx = 0;
	if (!(t_map.int_arr = (int**)malloc(sizeof(int*) * (100 + 1))))
		return ;
	t_map.y = 0;
	t_map.x = 0;
	while (t_map.file[t_map.y] != NULL)
	{
		if (!(t_map.int_arr[yy] = (int*)malloc(sizeof(int) * (t_map.origspaces + 1 + 1))))
				return ;
		while (t_map.file[t_map.y][t_map.x] != '\0')
		{
			t_map.file[t_map.y] = t_map.file[t_map.y] + t_map.x;
			val = ft_atoi(t_map.file[t_map.y]);
			t_map.int_arr[yy][xx] = val;
			xx++;
			while (t_map.file[t_map.y][t_map.x] >= '0' && t_map.file[t_map.y][t_map.x] <= '9' \
			&& t_map.file[t_map.y][t_map.x] != '\0')
				t_map.x++;
		}
		t_map.int_arr[yy][xx] = '\0';
		t_map.x = 0;
		xx = 0;
		t_map.y++;
		yy++;
	}
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

int		ft_valid_spaces()
{
	t_map.y = 0;
	t_map.x = 0;
	t_map.spaces = 0;
	while (t_map.file[t_map.y] != NULL)
	{
		while (t_map.file[t_map.y][t_map.x] != '\0')
		{
			if (t_map.file[t_map.y][t_map.x] == ' ' && t_map.file[t_map.y][t_map.x - 1] != ' ')
				t_map.spaces++;
			t_map.x++;
		}
		if (t_map.y == 0)
			t_map.origspaces = t_map.spaces;
		if (t_map.origspaces != t_map.spaces)
			return (0);
		t_map.y++;
		t_map.x = 0;
		t_map.spaces = 0;
	}
	return (1);
}

int		ft_valid_file()
{
	if (ft_valid_spaces() != 0 && ft_valid_numbers() != 0)
	{
		ft_get_z();
		return (1);
	}
	return (0);
}
