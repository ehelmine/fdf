/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:13:04 by ehelmine          #+#    #+#             */
/*   Updated: 2020/12/09 19:34:00 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		str[y++] = ft_atoi(ptr);
		if (str[y - 1] > 999)
			ft_error_handling(8);
		all->numbers_in_row++;
		while (ptr[x] != ' ' && ptr[x] != '\0')
			x++;
		ptr = ptr + x;
		x = 0;
		if (ptr[x] == ' ' && ptr[x + 1] == '\0')
			break ;
	}
	if (all->numbers_in_row != all->first_row_num)
		ft_error_handling(7);
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

int		ft_valid_file(t_map *all)
{
	ft_before_get_z(all);
	ft_get_z(all);
	all->box_val = 10;
	all->color = GREEN;
	all->chara = 'p';
	all->change_z = 10;
	all->change_x = 0;
	all->change_y = 0;
	all->amp = 1;
	all->angle = 0.523599;
	return (1);
}
