/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 09:42:02 by ehelmine          #+#    #+#             */
/*   Updated: 2020/06/30 15:03:13 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” substring
** from the string given as argument. The substring begins at
** indexstart and is of size len. If start and len aren’t refering to a valid
** substring, the behavior is undefined. If the allocation fails,
** the function returns NULL.
*/

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*nwstr;
	unsigned int	i;

	if (!(nwstr = (char *)malloc(sizeof(*nwstr) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		nwstr[i] = s[start];
		i++;
		start++;
	}
	nwstr[i] = '\0';
	return (nwstr);
}
