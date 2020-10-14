/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:54:18 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/14 15:47:05 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_exit(void)
{
	exit(0);
}

int		ft_choose_key(int key)
{
	if (key == ESC_KEY)
		exit(0);
	ft_putnbr(key);
	ft_putchar(' ');
	return (0);
}

char	**ft_read_file(char *str)
{
	int		fd;
	size_t	len;
	struct	All all1;

	all1.y = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (!(all1.file = (char**)malloc(sizeof(char*) * 5000)))
		return (NULL);
	while (get_next_line(fd, &all1.line) > 0)
	{
		len = ft_strlen(all1.line);
		if (len == 0)
			return (NULL);
		if (!(all1.file[all1.y] = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		all1.file[all1.y][len] = '\0';
		all1.file[all1.y] = ft_memmove(all1.file[all1.y], all1.line, len);
		free(all1.line);
		all1.line = NULL;
		all1.y++;
	}
	all1.file[all1.y] = NULL;
	return (all1.file);
}

int		main(int argc, char **argv)
{
	char *ptr = "My FDF";
	int color;
	struct All all1;

	all1.file = NULL;
	if (argc != 2)
		return (0);
	else
	{
		all1.file = ft_read_file(argv[1]);
		if (all1.file == NULL)
			return (0);
		if (!(ft_valid_file(all1.file)))
			return (0);
		color = 0X00ff00;
		all1.mlx_ptr = mlx_init();
		all1.win_ptr = mlx_new_window(all1.mlx_ptr, 500, 500, ptr);
		all1.y = 250;
		all1.x = 250;
		while (all1.y < 300)
			mlx_pixel_put(all1.mlx_ptr, all1.win_ptr, all1.x, all1.y++, color);
		while (all1.x < 300)
			mlx_pixel_put(all1.mlx_ptr, all1.win_ptr, all1.x++, all1.y, color);
		while (all1.x < 350 && all1.y < 350)
			mlx_pixel_put(all1.mlx_ptr, all1.win_ptr, all1.x++, all1.y++, color);
		mlx_key_hook(all1.win_ptr, ft_choose_key, (void*)0);
		mlx_hook(all1.win_ptr, 17, 0, ft_exit, (void*)0);
		mlx_loop(all1.mlx_ptr);
	}
	return (0);
}
