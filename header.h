/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 23:50:24 by ehelmine          #+#    #+#             */
/*   Updated: 2020/10/14 15:39:34 by ehelmine         ###   ########.fr       */
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

struct All
{
	int y;
	int x;
	int spaces;
	int origspaces;
	char **file;
	char *line;
	void *mlx_ptr;
	void *win_ptr;
};

int		ft_valid_file(char **file);

#endif
