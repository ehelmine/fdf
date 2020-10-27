/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 23:50:24 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/27 15:31:17 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define ESC_KEY								53
# define XK_ESCAPE                        0xff1b
# define XK_LEFT                          0xff51  /* Move left, left arrow */
# define XK_UP                            0xff52  /* Move up, up arrow */
# define XK_RIGHT                         0xff53  /* Move right, right arrow */
# define XK_DOWN                          0xff54  /* Move down, down arrow */
# include "mlx.h"
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_map
{
	int key;
	int y;
	int yy;
	int x;
	int xx;
	int columns;
	char **file;
	int **int_arr;
	char *line;
	void *mlx_ptr;
	void *win_ptr;
	int numbers_in_row;
	int first_row_num;
	int rows;
	int slope;
	int box;
	int color;
	int next;
	int val;
	int start;
	void *image;
	int size_l;
	int endian;
	int bpp;
	int *pic;
	int last;
	int left_corn;
	char chara;
	int in;
}				t_map;

int		ft_valid_file();

#endif
