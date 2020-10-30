/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:13:04 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/30 14:33:58 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

char	*skip_character(char *str, char c)
{
	int i;
	char *ptr;

	ptr = str;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i - 1] == c)
			return (str + i);
		else
			i++;
	}
	return (ptr);
}

void	ft_get_z(t_map *all)
{
	int ii;
	
	ii = 1;
	printf("here\n");
	while (all->file[all->y] != NULL)
	{
		if (!(all->int_arr[all->yy] = (int*)malloc(sizeof(int) * (1000))))
			return ;
		while (all->file[all->y][all->x] != '\0')
		{
			all->val = ft_atoi(all->file[all->y]);
			if (all->y == 0)
				all->first_row_num++;
			all->numbers_in_row++;
			all->int_arr[all->yy][all->xx++] = all->val;
			while (all->file[all->y][all->x] != '\0' && \
			all->file[all->y][all->x] != ' ')
				all->x++;
			while (all->file[all->y][all->x] != '\0' && \
			all->file[all->y][all->x] == ' ')
				all->x++;
			all->file[all->y] = all->file[all->y] + all->x;
//			all->file[all->y] = skip_character(all->file[all->y], ' ');
			all->x = 0;
		}
		printf("first row num %i in %i\n", all->first_row_num, ii);
		printf("number in this row %i\n", all->numbers_in_row);
		ii++;
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
/*	Check if it is a valid file, then declare some variables, and then get all z
**	coordinates to int array. Then declare here some other things before going back
**	to create the image.
*/

int		ft_valid_file(t_map *all)
{
	if (ft_valid_numbers(all) != 0)
	{
		ft_before_get_z(all);
		ft_get_z(all);
		if (all->first_row_num > 40)
			all->box_val = 0;
		else
			all->box_val = 15;
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
