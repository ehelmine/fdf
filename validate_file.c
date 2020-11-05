/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:13:04 by ehelmine          #+#    #+#             */
/*   Updated: 2020/11/04 11:06:20 by ehelmine         ###   ########.fr       */
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
	printf("%i\n", all->numbers_in_row);
	printf("%i\n", all->first_row_num);
	if (all->numbers_in_row != all->first_row_num)
		exit(0);
	all->numbers_in_row = 0;
}

void	ft_get_z(t_map *all)
{
	while (all->file[all->y][all->x] != '\0')
	{
		if (all->file[all->y][all->x] == ' ' && \
		all->file[all->y][all->x - 1] != ' ' && \
		all->file[all->y][all->x + 1] != '\0')
			all->first_row_num++;
		all->x++;
	}
	all->first_row_num += 1;
	all->x = 0;
	all->y = 0;
	while (all->file[all->y] != NULL)
	{
		if (!(all->int_arr[all->yy] = (int*)malloc(sizeof(int) * (50000))))
			return ;
		ft_get_z_2(all->int_arr[all->yy], all->file[all->y], all);
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
	while (all->file[all->y][all->x] != '\0' && \
	all->file[all->y][all->x] == ' ')
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
			if ((all->file[all->y][all->x] >= '0' && \
			all->file[all->y][all->x] <= '9') \
			|| all->file[all->y][all->x] == ' ' \
			|| all->file[all->y][all->x] == '-')
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
			all->box_val = 0;
		else
			all->box_val = 16;
		all->color = GREEN;
		return (1);
	}
	return (0);
}

/*
**	The first argument is sent to ft_read_file. We 1. open the file,
**	2. malloc always 5000 rows for it,
**	3. send it to get_next_line to get one line back,
**	4. check the length of variable line,
**	5. malloc space for that row, put '\0' in the end of **file row,
**	and then use ft_memmove to move line to our char array.
**	Repeat until get_next_line returns 0.
*/

void	ft_read_file(t_map *all, char *str)
{
	int		fd;
	size_t	len;

	all->y = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return ;
	if (!(all->file = (char**)malloc(sizeof(char*) * 5000)))
		return ;
	while (get_next_line(fd, &all->line) > 0)
	{
		len = ft_strlen(all->line);
		if (len == 0)
			return ;
		if (!(all->file[all->y] = (char*)malloc(sizeof(char) * (len + 1))))
			return ;
		all->file[all->y][len] = '\0';
		all->file[all->y] = ft_memmove(all->file[all->y], all->line, len);
		free(all->line);
		all->line = NULL;
		all->y++;
	}
	all->file[all->y] = NULL;
	return ;
}
