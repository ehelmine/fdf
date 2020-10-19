/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:13:04 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/16 12:06:07 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	ft_get_z(char **file)
{
	int val;
	struct All all1;

	all1.y = 0;
	all1.x = 0;
	while (file[all1.y] != NULL)
	{
		while (file[all1.y][all1.x] != '\0')
		{
			file[all1.y] = file[all1.y] + all1.x;
			val = ft_atoi(file[all1.y]);
			printf("val %i\n", val);

			while (file[all1.y][all1.x] >= '0' && file[all1.y][all1.x] <= '9' \
			&& file[all1.y][all1.x] != '\0')
				all1.x++;
		}
		all1.x = 0;
		all1.y++;
	}
}

int		ft_valid_numbers(char **file)
{
	struct All all1;

	all1.y = 0;
	all1.x = 0;
	while (file[all1.y] != NULL)
	{
		while (file[all1.y][all1.x] != '\0')
		{
			if ((file[all1.y][all1.x] >= '0' && file[all1.y][all1.x] <= '9') \
			|| file[all1.y][all1.x] == ' ' || file[all1.y][all1.x] == '-')
				all1.x++;
			else
				return (0);
		}
		all1.y++;
		all1.x = 0;
	}
	return (1);
}

int		ft_valid_spaces(char **file)
{
	struct All all1;

	all1.y = 0;
	all1.x = 0;
	all1.spaces = 0;
	while (file[all1.y] != NULL)
	{
		while (file[all1.y][all1.x] != '\0')
		{
			if (file[all1.y][all1.x] == ' ' && file[all1.y][all1.x - 1] != ' ')
				all1.spaces++;
			all1.x++;
		}
		if (all1.y == 0)
			all1.origspaces = all1.spaces;
		if (all1.origspaces != all1.spaces)
			return (0);
		all1.y++;
		all1.x = 0;
		all1.spaces = 0;
	}
	all1.numbers_in_row = all1.origspaces + 1;
	printf("numbers in rows %i\n", all1.numbers_in_row);
	return (1);
}

int		ft_valid_file(char **file)
{
	if (ft_valid_spaces(file) != 0 && ft_valid_numbers(file) != 0)
	{
		ft_get_z(file);
		return (1);
	}
	return (0);
}
