/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:15:15 by ehelmine          #+#    #+#             */
/*   Updated: 2020/12/08 23:50:37 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_proj_loop(t_map *all)
{
	if (all->x > 0 && all->y > 0 && all->x < SIZE && all->y < SIZE)
		all->pic[(int)all->x + (all->size_l * (int)all->y)] = \
		all->color;
	all->y = all->y + all->dy;
	all->x = all->x + all->dx;
	all->i_slope++;
}

void	ft_error_handling(int error)
{
	if (error == 1)
		ft_putstr("ERROR: Open fail\n");
	else if (error == 2)
		ft_putstr("ERROR: Can not read given file\n");
	else if (error == 3)
		ft_putstr("ERROR: Length of line is 0\n");
	else if (error == 4)
		ft_putstr("ERROR: Empty file\n");
	else if (error == 5)
		ft_putstr("ERROR: Malloc fail\n");
	else if (error == 6)
		ft_putstr("ERROR: Not valid content\n");
	else if (error == 7)
		ft_putstr("ERROR: Lines are not same length\n");
	exit(0);
}

void	ft_free(void **array)
{
	int y;

	y = 0;
	while (array[y] != NULL)
	{
		ft_putstr(array[y]);
		ft_putchar('\n');
		free(array[y]);
		y++;
	}
	free(array);
	array = NULL;
}
