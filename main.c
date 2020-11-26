/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:54:18 by ehelmine          #+#    #+#             */
/*   Updated: 2020/11/26 14:34:04 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error_handling(int error)
{
	if (error == 1)
		ft_putstr("ERROR: Open fail\n");
	else if (error == 2)
		ft_putstr("ERROR: Get_next_line fail\n");
	else if (error == 3)
		ft_putstr("ERROR: Length of line is 0\n");
	else if (error == 4)
		ft_putstr("ERROR: Empty file\n");
	else if (error == 5)
		ft_putstr("ERROR: Malloc fail\n");
	else if (error == 6)
		ft_putstr("ERROR: Not valid numbers\n");
	exit(0);
}

void	ft_call_draws(t_map *all)
{
	if (all->chara == 'p')
	{
		ft_values_for_print_v(all);
		ft_print_base_vertical(all);
		ft_values_for_print_h(all);
		ft_print_base_horizontal(all);
	}
	else if (all->chara == 'i')
	{
		ft_values_for_iso_v(all);
		ft_print_isometric_v(all);
		ft_values_for_iso_h(all);
		ft_print_isometric_h(all);
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->image, 0, 0);
	mlx_key_hook(all->win_ptr, &ft_choose_key, all);
	mlx_hook(all->win_ptr, 17, 0, ft_exit, (void*)0);
}

void	ft_image_control(t_map *all)
{
	all->image = mlx_new_image(all->mlx_ptr, SIZE, SIZE);
	all->pic = (int*)mlx_get_data_addr(all->image, &all->bpp, \
	&all->size_l, &all->endian);
	all->size_l /= 4;
	all->rows = 0;
	while (all->int_arr[all->rows] != NULL)
		all->rows++;
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

int		ft_read_file(t_map *all, char *str)
{
	int		fd;
	size_t	len;
	int		x;

	x = 0;
	all->y = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error_handling(1);
	if (!(all->file = (char**)malloc(sizeof(char*) * 5000)))
		ft_error_handling(5);
	while ((x = get_next_line(fd, &all->line)) > 0)
	{
		if (x == -1)
			ft_error_handling(2);
		len = ft_strlen(all->line);
		if (len == 0)
			ft_error_handling(3);
		if (!(all->file[(int)all->y] = (char*)malloc(sizeof(char) * (len + 1))))
			ft_error_handling(5);
		all->file[(int)all->y][len] = '\0';
		all->file[(int)all->y] = ft_memmove(all->file[(int)all->y], \
		all->line, len);
		free(all->line);
		all->line = NULL;
		all->y++;
	}
	if (x == -1)
		ft_error_handling(2);
	all->file[(int)all->y] = NULL;
	return (1);
}

int		main(int argc, char **argv)
{
	t_map all;

	all.file = NULL;
	if (argc != 2)
		ft_putstr("usage: ./fdf <filename>\n");
	else
	{
		ft_read_file(&all, argv[1]);
		if (all.file[0] == NULL)
			ft_error_handling(4);
		if (!(ft_valid_file(&all)))
			ft_error_handling(6);
		all.mlx_ptr = mlx_init();
		if (all.mlx_ptr == NULL)
			return (0);
		all.win_ptr = mlx_new_window(all.mlx_ptr, SIZE, SIZE, "my fdf");
		ft_image_control(&all);
		ft_call_draws(&all);
		mlx_key_hook(all.win_ptr, &ft_choose_key, &all);
		mlx_hook(all.win_ptr, 17, 0, ft_exit, (void*)0);
		mlx_loop(all.mlx_ptr);
	}
	return (0);
}
