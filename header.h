/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 23:50:24 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/19 12:54:06 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define ESC_KEY								53
# include "mlx.h"
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

struct			s_map
{
	int y;
	int x;
	int spaces;
	int origspaces;
	char **file;
	int **int_arr;
	char *line;
	void *mlx_ptr;
	void *win_ptr;
	int numbers_in_row;
	int rows;
	int slope;
}				t_map;

int		ft_valid_file();

#endif
