/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 23:50:24 by ehelmine          #+#    #+#             */
/*   Updated: 2020/11/06 11:13:39 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define SIZE						1200
# define ESC_KEY					53
# define ZOOM_IN					105
# define ZOOM_OUT					111
# define MOVE_LEFT					123
# define MOVE_RIGHT					124
# define MOVE_UP					126
# define MOVE_DOWN					125
# define ISOMETRIC					37
# define PARALLEL					35
# define XK_ESCAPE					0xff1b
# define XK_LEFT					0xff51
# define XK_UP						0xff52
# define XK_RIGHT					0xff53
# define XK_DOWN					0xff54
# define GREEN						0X00ff00
# define BLUE						0x00FFFF
# define RED						0xFF0000
# define YELLOW						0xFFFF00
# include "mlx.h"
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef struct		s_map
{
	float val_2;
	float val_1;
	int key;
	float y;
	int yy;
	float x;
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
	float slope;
	int box;
	int color;
	float next_x;
	float next_y;
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
	int box_val;
	float change_y;
	float change_x;
	float dx;
	float dy;
	float change_z;
	float i_slope;
	int i;
	int ii;
}				t_map;

int		ft_valid_file(t_map *all);
void	ft_print_base_horizontal(t_map *all);
void	ft_print_base_vertical(t_map *all);
int		ft_choose_key(int key, t_map *all);
void	ft_image_control(t_map *all);
void	ft_call_draws(t_map *all);
void	ft_values_for_print_v(t_map *all);
void	ft_values_for_print_h(t_map *all);
int		ft_exit(void);
void	ft_read_file(t_map *all, char *str);
void	ft_values_for_iso_v(t_map *all);
void	ft_isometric_v(t_map *all, float val_1, float val_2);
void	ft_print_isometric_v(t_map *all);
void	ft_values_for_iso_h(t_map *all);
void	ft_isometric_h(t_map *all, float val_1, float val_2);
void	ft_print_isometric_h(t_map *all);
void	ft_dda(t_map *all);
float	abs_val(float x);

#endif
