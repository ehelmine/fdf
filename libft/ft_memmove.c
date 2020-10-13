/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:41:29 by ehelmine          #+#    #+#             */
/*   Updated: 2020/07/06 13:35:12 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**   The memmove() function copies len bytes from string src to string dst.
**   The two strings may overlap; the copy is always done in a non-destructive
**   manner.
**
** RETURN VALUES
**     The memmove() function returns the original value of dst.
*/

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dsst;
	const char	*srrc;
	char		temp[len];

	dsst = (char *)dst;
	srrc = (char *)src;
	i = 0;
	if (len == 0)
		return (dst);
	if (dst || src)
	{
		while (i < len)
		{
			temp[i] = srrc[i];
			i++;
		}
		i = 0;
		while (i < len)
		{
			dsst[i] = temp[i];
			i++;
		}
	}
	return (dst);
}
