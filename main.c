/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:54:18 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/30 12:22:41 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//	all.slope = (140-100) / (160-100);
//	while (all.y + all.slope < 300 && all.x + 1 < 300)
//		mlx_pixel_put(all.mlx_ptr, all.win_ptr, all.x++, all.y++, all.color);

int		ft_exit(void)
{
	exit(0);
}

void	ft_values_for_print(t_map *all)
{
	all->rows = 0;
	while (all->int_arr[all->rows] != NULL)
		all->rows++;
	all->y = 0 + all->change_y;
	all->x = 0 + all->change_x;
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
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->image, 0, 0);
	mlx_key_hook(all->win_ptr, &ft_choose_key, all);
	mlx_hook(all->win_ptr, 17, 0, ft_exit, (void*)0);
}

void	ft_image_control(t_map *all)
{
	all->image = mlx_new_image(all->mlx_ptr, 1500, 1200);
	all->pic = (int*)mlx_get_data_addr(all->image, &all->bpp, &all->size_l, &all->endian);
	all->size_l /= 4;
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
		all.box_val = 0;
		all.color = GREEN;
		ft_image_control(&all);
		ft_call_draws(&all);
		mlx_loop(all.mlx_ptr);
	}
	return (0);
}
