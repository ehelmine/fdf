/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:54:18 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/29 14:20:10 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <math.h>
#include <mlx.h>

//	all.slope = (140-100) / (160-100);
//	while (all.y + all.slope < 300 && all.x + 1 < 300)
//		mlx_pixel_put(all.mlx_ptr, all.win_ptr, all.x++, all.y++, all.color);

int		ft_exit(void)
{
	exit(0);
}

void	ft_isometric_x(t_map *all)
{
	float prev_x;
	float org_x;
	float org_y;

	org_x = all->x;
	org_y = all->y;
	all->x = (org_x - org_y) * cos(0.8);
	prev_x = all->next_x;
	all->next_x = (prev_x - org_y) * cos(0.8);
	all->y = -(1) + ((org_x + org_y) * sin(0.5));
}

void	ft_isometric_y(t_map *all)
{
	float prev_x;
	float prev_y;
	float org_x;
	float org_y;

	org_x = all->x;
	org_y = all->y;
	prev_x = all->x;
	prev_y = all->y;
	all->y = -(2) + ((prev_x + prev_y) * sin(0.5));
	prev_y = all->next_y;
	all->next_y = -(3) + ((prev_x + prev_y) * sin(0.5));
	all->x = (org_x - org_y) * cos(0.8);
}

void	ft_print_base_vertical(t_map *all)
{
	all->next_y = all->y + all->box;
	all->columns = all->first_row_num;
	all->yy = all->rows - 1;
//	ft_isometric_y(all);
	while (all->columns > 0)
	{
		while (all->yy > 0)
		{
			while (all->y < all->next_y)
				all->pic[all->x + (all->size_l * all->y++)] = 0XFFFFFF;
			all->next_y = all->y + all->box;
//			ft_isometric_y(all);
			all->yy--;
			if (all->next_y > 1200 || all->x > 1500)
				break ;
		}
		all->yy = all->rows - 1;
		all->columns--;
		all->y = 0;
		all->x = all->x + all->box;
		all->next_y = all->y + all->box;
//		ft_isometric_y(all);
	}
}

void	ft_print_base_horizontal(t_map *all)
{
	printf("how many columns %i\n", all->first_row_num);
	printf("how many rows %i\n", all->rows);
	all->next_x = all->x + all->box;
	all->columns = all->first_row_num - 1;
	all->yy = all->rows;
//	ft_isometric_x(all);
	while (all->yy > 0)
	{
		while (all->columns > 0)
		{
			while (all->x < all->next_x)
				all->pic[all->x++ + (all->size_l * all->y)] = all->color;
			all->columns--;
			all->next_x = all->x + all->box;
			if (all->next_x > 1500 || all->y > 1200)
				break ;
		}
		all->columns = all->first_row_num - 1;
		all->yy--;
		all->x = 0;
		all->y = all->y + all->box;
		all->next_x = all->x + all->box;
//		ft_isometric_x(all);
	}
}

void	ft_values_for_print(t_map *all)
{
	all->rows = 0;
	while (all->int_arr[all->rows] != NULL)
		all->rows++;
	all->color = 0X00ff00;
	all->y = 0;
	all->x = 0;
	all->box = 5 + all->box_val;
	all->next_x = all->x + all->box;
	all->next_y = all->y;
}

void	ft_call_draws(t_map *all)
{
	ft_values_for_print(all);
	ft_print_base_vertical(all);
	ft_values_for_print(all);
	ft_print_base_horizontal(all);
}

void	ft_image_control(t_map *all)
{
	all->image = mlx_new_image(all->mlx_ptr, 1500, 1200);
	all->pic = (int*)mlx_get_data_addr(all->image, &all->bpp, &all->size_l, &all->endian);
	all->size_l /= 4;
}

int		ft_choose_key(int key, t_map *all)
{
	ft_putnbr(key);
	if (key == ZOOM_IN || key == 34)
	{
		ft_memset(all->pic, 0, all->size_l);
		ft_image_control(all);
		all->box_val += 1;
		ft_values_for_print(all);
		ft_print_base_vertical(all);
		ft_values_for_print(all);
		ft_print_base_horizontal(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->image, 0, 0);
	}
	if ((key == ZOOM_OUT || key == 31) && all->box > 2)
	{
		ft_memset(all->pic, 0, all->size_l);
		ft_image_control(all);
		all->box_val -= 1;
		ft_values_for_print(all);
		ft_print_base_vertical(all);
		ft_values_for_print(all);
		ft_print_base_horizontal(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->image, 0, 0);
	}
	if (key == ESC_KEY || key == XK_ESCAPE)
	{
	//	system("leaks fdf");
		exit(0);
	}
	if (key == MOVE_LEFT || key == XK_LEFT)
		exit(0);
	if (key == MOVE_RIGHT || key == XK_RIGHT)
		exit(0);
	if (key == MOVE_UP || key == XK_UP)
		exit(0);
	if (key == MOVE_DOWN || key == XK_DOWN)
		exit(0);
	ft_putchar(' ');
	return (1);
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
		all.win_ptr = mlx_new_window(all.mlx_ptr, 1500, 1200, "my fdf");
		ft_image_control(&all);
		all.chara = 'i';
		all.box_val = 0;
		ft_call_draws(&all);
		mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.image, 0, 0);
		mlx_key_hook(all.win_ptr, &ft_choose_key, &all);
		mlx_hook(all.win_ptr, 17, 0, ft_exit, (void*)0);
		mlx_loop(all.mlx_ptr);
	}
	return (0);
}
