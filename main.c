/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:54:18 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/22 12:50:40 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		ft_exit(void)
{
	exit(0);
}

void	ft_print_base_vertical()
{
	t_map.next = 51 + ((t_map.rows - 1) * t_map.box);
	t_map.columns = t_map.first_row_num;
	t_map.yy = t_map.rows;
	while (t_map.columns > 0)
	{
		while (t_map.y < t_map.next)
			mlx_pixel_put(t_map.mlx_ptr, t_map.win_ptr, t_map.x, t_map.y++, t_map.color);
		t_map.columns--;
		t_map.y = 50;
		t_map.x = t_map.x + t_map.box;
	}
}

void	ft_print_base_horizontal()
{
	printf("how many columns %i\n", t_map.first_row_num);
	printf("how many rows %i\n", t_map.rows);
//	t_map.slope = (140-100) / (160-100);
//	while (t_map.y + t_map.slope < 300 && t_map.x + 1 < 300)
//		mlx_pixel_put(t_map.mlx_ptr, t_map.win_ptr, t_map.x++, t_map.y++, t_map.color);
	t_map.next = 51 + ((t_map.first_row_num - 1) * t_map.box);
	t_map.columns = t_map.first_row_num;
	t_map.yy = t_map.rows;
	while (t_map.yy > 0)
	{
		while (t_map.x < t_map.next)
			mlx_pixel_put(t_map.mlx_ptr, t_map.win_ptr, t_map.x++, t_map.y, t_map.color);
		t_map.yy--;
		t_map.x = 50;
		t_map.y = t_map.y + t_map.box;
	}
}

void	ft_values_for_print_vertical(int start)
{
	
	t_map.rows = 0;
	while (t_map.int_arr[t_map.rows] != NULL)
		t_map.rows++;
	t_map.color = 0X00ff00;
	t_map.y = 50;
	t_map.x = 50;
	t_map.box = 10;
	t_map.start = start;
	if (t_map.first_row_num > 70 || t_map.rows > 70)
		t_map.box = 5;
}

void	ft_values_for_print_horizontal(int start)
{
	
	t_map.rows = 0;
	while (t_map.int_arr[t_map.rows] != NULL)
		t_map.rows++;
	t_map.color = 0X00ff00;
	t_map.y = 50;
	t_map.x = 50;
	t_map.box = 10;
	t_map.start = start;
	if (t_map.first_row_num > 70 || t_map.rows > 70)
		t_map.box = 5;
}

int		ft_choose_key(int key)
{
	if (key == ESC_KEY || key == XK_ESCAPE)
		exit(0);
	if (key == 123 || key == XK_LEFT)
		mlx_pixel_put(t_map.mlx_ptr, t_map.win_ptr, t_map.x--, t_map.y, 0X00ff00);
	if (key == 124 || key == XK_RIGHT)
		mlx_pixel_put(t_map.mlx_ptr, t_map.win_ptr, t_map.x++, t_map.y, 0X00ff00);
	if (key == 126 || key == XK_UP)
		mlx_pixel_put(t_map.mlx_ptr, t_map.win_ptr, t_map.x, t_map.y--, 0X00ff00);
	if (key == 125 || key == XK_DOWN)
		mlx_pixel_put(t_map.mlx_ptr, t_map.win_ptr, t_map.x, t_map.y++, 0X00ff00);
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

void	ft_read_file(char *str)
{
	int		fd;
	size_t	len;

	t_map.y = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return ;
	if (!(t_map.file = (char**)malloc(sizeof(char*) * 5000)))
		return ;
	while (get_next_line(fd, &t_map.line) > 0)
	{
		len = ft_strlen(t_map.line);
		if (len == 0)
			return ;
		if (!(t_map.file[t_map.y] = (char*)malloc(sizeof(char) * (len + 1))))
			return ;
	 	t_map.file[t_map.y][len] = '\0';
	 	t_map.file[t_map.y] = ft_memmove(t_map.file[t_map.y], t_map.line, len);
		free(t_map.line);
		t_map.line = NULL;
		t_map.y++;
	}
	t_map.file[t_map.y] = NULL;
	return ;
}

int		main(int argc, char **argv)
{
	t_map.file = NULL;
	if (argc != 2)
		return (0);
	else
	{
		ft_read_file(argv[1]);
		if (t_map.file == NULL)
			return (0);
		if (!(ft_valid_file()))
			return (0);
		t_map.mlx_ptr = mlx_init();
		if (t_map.mlx_ptr == NULL)
			return (0);
		t_map.win_ptr = mlx_new_window(t_map.mlx_ptr, 1200, 1000, "my fdf");
		ft_values_for_print_vertical(50);
		ft_print_base_vertical();
		ft_values_for_print_horizontal(50);
		ft_print_base_horizontal();
		mlx_key_hook(t_map.win_ptr, ft_choose_key, (void*)0);
		mlx_hook(t_map.win_ptr, 17, 0, ft_exit, (void*)0);
		mlx_loop(t_map.mlx_ptr);
//		mlx_clear_window t_map.mlx_ptr, t_map.win_ptr);
//		mlx_destroy_window t_map.mlx_ptr, t_map.win_ptr);
	}
	return (0);
}
