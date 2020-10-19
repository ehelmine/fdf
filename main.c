/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:54:18 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/19 13:50:48 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

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

void	ft_print_base()
{
	int i;
	int color;

	color = 0X00ff00;
	i = 0;
	printf("how man columns %i\n", t_map.origspaces + 1);
	while (t_map.file[i] != NULL)
		i++;
	printf("how many rows %i\n", i);
	t_map.y = 100;
	t_map.x = 100;
	t_map.slope = (140-100) / (160-100);
	while (t_map.y + t_map.slope < 300 && t_map.x + 1 < 300)
		mlx_pixel_put(t_map.mlx_ptr, t_map.win_ptr, t_map.x++, t_map.y++, color);
	mlx_key_hook(t_map.win_ptr, ft_choose_key, (void*)0);
	mlx_hook(t_map.win_ptr, 17, 0, ft_exit, (void*)0);
	mlx_loop(t_map.mlx_ptr);
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
		t_map.win_ptr = mlx_new_window(t_map.mlx_ptr, 1000, 1000, "my fdf");
		ft_print_base();
//		mlx_clear_window t_map.mlx_ptr, t_map.win_ptr);
//		mlx_destroy_window t_map.mlx_ptr, t_map.win_ptr);
	}
	return (0);
}
