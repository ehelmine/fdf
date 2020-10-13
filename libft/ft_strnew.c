/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:49:30 by ehelmine          #+#    #+#             */
/*   Updated: 2020/07/04 17:39:11 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description Allocates (with malloc(3)) and returns a “fresh” string ending
**  with ’\0’. Each character of the string is initialized at
** ’\0’. If the allocation fails the function returns NULL.
** Param. #1 The size of the string to be allocated.
** Return value The string allocated and initialized to 0.
** Libc functions malloc(3)
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *newstr;

	if (!(newstr = (char *)malloc(sizeof(*newstr) * size + 1)))
		return (NULL);
	else
	{
		ft_memset(newstr, 0, size + 1);
		return (newstr);
	}
	return (NULL);
}
