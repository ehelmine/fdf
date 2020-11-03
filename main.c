/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:54:18 by ehelmine          #+#    #+#             */
/*   Updated: 2020/11/03 16:50:33 by ehelmine         ###   ########.fr       */
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

void	ft_values_for_print_h(t_map *all)
{
	all->rows = 0;
	while (all->int_arr[all->rows] != NULL)
		all->rows++;
	all->y = 0 + all->change_y;
	all->x = 0 + all->change_x;
	all->box = 5 + all->box_val;
	all->next_x = all->x + all->box;;
	all->next_y = all->y;
}

void	ft_values_for_print_v(t_map *all)
{
	all->rows = 0;
	while (all->int_arr[all->rows] != NULL)
		all->rows++;
	all->y = 0 + all->change_y;
	all->x = 0 + all->change_x;
	all->box = 5 + all->box_val;
	all->next_x = all->x;
	all->next_y = all->y + all->box;
}

void	ft_call_draws(t_map *all)
{
	ft_values_for_print_v(all);
//	ft_print_base_vertical(all);
	ft_print_isometric_v(all);
	printf("\ncheck\n");
	ft_values_for_print_h(all);
//	ft_print_base_horizontal(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->image, 0, 0);
	mlx_key_hook(all->win_ptr, &ft_choose_key, all);
	mlx_hook(all->win_ptr, 17, 0, ft_exit, (void*)0);
}

void	ft_image_control(t_map *all)
{
	all->image = mlx_new_image(all->mlx_ptr, 1000, 700);
	all->pic = (int*)mlx_get_data_addr(all->image, &all->bpp, \
	&all->size_l, &all->endian);
	all->size_l /= 4;
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
		all.win_ptr = mlx_new_window(all.mlx_ptr, 1000, 700, "my fdf");
		ft_image_control(&all);
		ft_call_draws(&all);
		mlx_key_hook(all.win_ptr, &ft_choose_key, &all);
		mlx_hook(all.win_ptr, 17, 0, ft_exit, (void*)0);
		mlx_loop(all.mlx_ptr);
	}
	return (0);
}
