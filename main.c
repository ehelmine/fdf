/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:54:18 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/13 10:39:19 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	char *ptr = "My FDF";
	int color;
	int y;
	int x;

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
	mlx_loop(mlx_ptr);
	return (0);
}