/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:54:18 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/13 16:16:04 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <fcntl.h>
#include "libft/includes/libft.h"
#include <stdio.h>

int		ft_exit(void)
{
	exit (0);
}

int		choose_key(int key)
{
	if (key == ESC_KEY)
		exit (0);
	ft_putnbr(key);
	ft_putchar(' ');
	return (0);
}

void	ft_read_file(char *str)
{
	int fd;
	char *line;
	int i;
	size_t len;
	char **file;
	int y;

	y = 0;
	fd = open(str, O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		len = ft_strlen(line);
		if (!(file))
		file[y] = ft_memalloc(len);
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
		line = NULL;
	}
}

int		main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;
	char *ptr = "My FDF";
	int color;
	int y;
	int x;
	char *line;

	line = NULL;
	if (argc != 2)
		return (0);
	else
	{
		ft_read_file(argv[1]);
		color = 0X00ff00;
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 500, 500, ptr);
		y = 250;
		x = 250;
		while (y < 300)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y++, color);
		while (x < 300)
			mlx_pixel_put(mlx_ptr, win_ptr, x++, y, color);
		while (x < 350 && y < 350)
			mlx_pixel_put(mlx_ptr, win_ptr, x++, y++, color);
		mlx_key_hook(win_ptr, choose_key, (void*)0);
		mlx_hook(win_ptr, 17, 0, ft_exit, (void*)0);
		mlx_loop(mlx_ptr);
	}
	return (0);
}