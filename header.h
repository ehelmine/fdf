/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 23:50:24 by ehelmine          #+#    #+#             */
/*   Updated: 2020/12/07 12:47:27 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define SIZE						700
# define ESC_KEY					53
# define XK_ESCAPE					0xff1b
# define ZOOM_IN					105
# define ZOOM_OUT					111
# define MOVE_LEFT					123
# define XK_LEFT					0xff51
# define MOVE_RIGHT					124
# define XK_RIGHT					0xff53
# define MOVE_UP					126
# define XK_UP						0xff52
# define MOVE_DOWN					125
# define XK_DOWN					0xff54
# define PROJECTIONS				108
# define PARALLEL					112
# define CHANGE_COLOR				99
# define MORE_HIGH					45
# define LESS_HIGH					61
# define GREEN						0X00ff00
# define BLUE						0x00FFFF
# define RED						0xFF0000
# define YELLOW						0xFFFF00
# define P							0xFFC0CB
# include "mlx.h"
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef struct	s_map
{
	size_t		len;
	int			fd;
	float		val_2;
	float		val_1;
	int			key;
	float		y;
	int			yy;
	float		x;
	int			xx;
	int			columns;
	char		**file;
	int			**int_arr;
	char		*line;
	void		*mlx_ptr;
	void		*win_ptr;
	int			numbers_in_row;
	int			first_row_num;
	int			rows;
	float		slope;
	int			box;
	int			color;
	float		next_x;
	float		next_y;
	int			val;
	void		*image;
	int			size_l;
	int			endian;
	int			bpp;
	int			*pic;
	char		chara;
	int			box_val;
	float		change_y;
	float		change_x;
	float		dx;
	float		dy;
	float		change_z;
	float		i_slope;
	int			i;
	int			ii;
	double		angle;
	int			check;
}				t_map;

int				ft_valid_file(t_map *all);
void			ft_error_handling(int error);
void			ft_print_base_horizontal(t_map *all);
void			ft_print_base_vertical(t_map *all);
int				ft_choose_key(int key, t_map *all);
void			ft_image_control(t_map *all);
void			ft_call_draws(t_map *all);
void			ft_values_for_print_v(t_map *all);
void			ft_values_for_print_h(t_map *all);
int				ft_exit(void);
int				ft_read_file(t_map *all, char *str);
void			ft_values_for_proj_v(t_map *all);
void			ft_projection_v(t_map *all, float val_1, float val_2);
void			ft_print_projection_v(t_map *all);
void			ft_values_for_proj_h(t_map *all);
void			ft_projection_h(t_map *all, float val_1, float val_2);
void			ft_print_projection_h(t_map *all);
void			ft_dda(t_map *all);
float			abs_val(float x);
void			ft_error_handling(int error);
void			ft_free(void **array);
void			ft_print_proj_loop(t_map *all);

#endif
