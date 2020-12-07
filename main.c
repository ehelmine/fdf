/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:54:18 by ehelmine          #+#    #+#             */
/*   Updated: 2020/12/07 12:18:10 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_instructions_to_window(t_map *all)
{
	mlx_string_put(all->mlx_ptr, all->win_ptr, 550, 50, P, "INSTRUCTIONS");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 550, 70, P, "ZOOM IN:  I");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 550, 90, P, "ZOOM OUT: O");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 550, 110, P, "Z UP:     +");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 550, 130, P, "Z DOWN:   -");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 550, 150, P, "MOVE:     ARROWS");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 550, 170, P, "FLAT:     P");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 550, 190, P, "OTHER:    L");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 550, 210, P, "COLOR:    C");
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
		ft_values_for_proj_v(all);
		ft_print_projection_v(all);
		ft_values_for_proj_h(all);
		ft_print_projection_h(all);
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->image, 0, 0);
	ft_instructions_to_window(all);
	mlx_key_hook(all->win_ptr, &ft_choose_key, all);
	mlx_hook(all->win_ptr, 17, 0, ft_exit, (void*)0);
	mlx_loop(all->mlx_ptr);
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
	all->fd = open(str, O_RDONLY);
	if (all->fd == -1)
		ft_error_handling(1);
	if (!(all->file = (char**)malloc(sizeof(char*) * 50000)))
		ft_error_handling(5);
	while ((all->xx = get_next_line(all->fd, &all->line)) > 0)
	{
		if (all->xx == -1)
			ft_error_handling(2);
		all->len = ft_strlen(all->line);
		if (all->len == 0)
			ft_error_handling(3);
		if (!(all->file[all->i] = (char*)malloc(sizeof(char) * (all->len + 1))))
			ft_error_handling(5);
		all->file[all->i][all->len] = '\0';
		all->file[all->i] = ft_memmove(all->file[all->i], all->line, all->len);
		free(all->line);
		all->line = NULL;
		all->i++;
	}
	if (all->xx == -1)
		ft_error_handling(2);
	all->file[all->i] = NULL;
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
		all.xx = 0;
		all.i = 0;
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
		ft_free((void**)all.int_arr);
	}
	return (0);
}
