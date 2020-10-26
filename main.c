/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:54:18 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/26 20:04:50 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

//	all.slope = (140-100) / (160-100);
//	while (all.y + all.slope < 300 && all.x + 1 < 300)
//		mlx_pixel_put(all.mlx_ptr, all.win_ptr, all.x++, all.y++, all.color);

int		ft_exit(void)
{
	exit(0);
}

void	ft_print_base_vertical(t_map *all)
{
	all->next = all->y + all->box;
	all->last = 50 + ((all->rows - 1) * all->box);
	all->columns = all->first_row_num;
	all->yy = all->rows;
	while (all->columns > 0)
	{
		while (all->y < all->last)
		{
			while (all->y < all->next)
				all->pic[all->x + (all->size_l * all->y++)] = all->color;
			all->next = all->y + all->box;
			if (all->color == 0xFFFFFF)
				all->color = 0X00ff00;
			else
				all->color = 0xFFFFFF;	
		}
		all->columns--;
		all->y = 50;
		all->x = all->x + all->box;
		all->next = all->y + all->box;
	}
}

void	ft_print_base_horizontal(t_map *all)
{
	printf("how many columns %i\n", all->first_row_num);
	printf("how many rows %i\n", all->rows);
	all->next = all->x + all->box;
	all->last = 50 + ((all->first_row_num - 1) * all->box);
	all->columns = all->first_row_num;
	all->yy = all->rows;
	while (all->yy > 0)
	{
		while (all->x < all->last)
		{
			while (all->x < all->next)
				all->pic[all->x++ + (all->size_l * all->y)] = all->color;
			all->next = all->x + all->box;
			if (all->color == 0xFFFFFF)
				all->color = 0X00ff00;
			else
				all->color = 0xFFFFFF;	
		}
		all->yy--;
		all->x = 50;
		all->y = all->y + all->box;
		all->next = all->x + all->box;
	}
}

void	ft_values_for_print_vertical(t_map *all, int start)
{
	all->rows = 0;
	while (all->int_arr[all->rows] != NULL)
		all->rows++;
	all->color = 0X00ff00;
	all->y = 50 + start;
	all->x = 50 + start;
	all->box = 10;
	all->start = start;
	if (all->first_row_num > 70 || all->rows > 70)
		all->box = 5;
	else if (all->first_row_num < 20 || all->rows < 20)
		all->box = 25;
}

void	ft_values_for_print_horizontal(t_map *all, int start)
{
	all->rows = 0;
	while (all->int_arr[all->rows] != NULL)
		all->rows++;
	all->color = 0X00ff00;
	all->y = 50 + start;
	all->x = 50 + start;
	all->box = 10;
	all->start = start;
	if (all->first_row_num > 70 || all->rows > 70)
		all->box = 5;
	else if (all->first_row_num < 20 || all->rows < 20)
		all->box = 25;
}

void	ft_call_draws(t_map *all, int start)
{
	ft_values_for_print_vertical(all, start);
	ft_print_base_vertical(all);
	ft_values_for_print_horizontal(all, start);
	ft_print_base_horizontal(all);
}

void	ft_image_control(t_map *all)
{
	all->image = mlx_new_image(all->mlx_ptr, 1200, 1000);
	all->pic = (int*)mlx_get_data_addr(all->image, &all->bpp, &all->size_l, &all->endian);
	all->size_l /= 4;
}

int		ft_choose_key(int key, t_map *all)
{
	if (key == ESC_KEY || key == XK_ESCAPE)
		exit(0);
	if (key == 123 || key == XK_LEFT)
		all->x = 3;
		exit(0);
	if (key == 124 || key == XK_RIGHT)
		exit(0);
	if (key == 126 || key == XK_UP)
		exit(0);
	if (key == 125 || key == XK_DOWN)
		exit(0);
	ft_putnbr(key);
	ft_putchar(' ');
	return (0);
}

/*
**	The first argument is sent to ft_read_file. We 1. open the file, 2. malloc always 5000 rows for it,
**	3. send it to get_next_line to get one line back, 4. check the length of variable line,
**	5. malloc space for that row, put '\0' in the end of **file row, and then use 
**	ft_memmove to move line to our char array. Repeat until get_next_line returns 0.
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

int		main(int argc, char **argv)
{
	t_map all;

	all.file = NULL;
	if (argc != 2)
		return (0);
	else
	{
		ft_read_file(&all, argv[1]);
		if (all.file == NULL)
			return (0);
		if (!(ft_valid_file(&all)))
			return (0);
		all.mlx_ptr = mlx_init();
		if (all.mlx_ptr == NULL)
			return (0);
		all.win_ptr = mlx_new_window(all.mlx_ptr, 1200, 1000, "my fdf");
		ft_image_control(&all);
		ft_call_draws(&all, 0);
		mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.image, 0, 0);
		mlx_key_hook(all.win_ptr, ft_choose_key, (void*)0);
		mlx_hook(all.win_ptr, 17, 0, ft_exit, (void*)0);
		mlx_loop(all.mlx_ptr);
	}
	return (0);
}
