/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:17:33 by ehelmine          #+#    #+#             */
/*   Updated: 2020/07/31 12:48:14 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description Allocates (with malloc(3)) and returns a “fresh” string ending
**  with ’\0’, result of the concatenation of s1 and s2. If
** the allocation fails the function returns NULL.
** Param. #1 The prefix string.
** Param. #2 The suffix string.
** Return value The “fresh” string result of the concatenation of the 2 strings.
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nwstr;
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	size_t	ii;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(nwstr = (char *)malloc(sizeof(*nwstr) * (s1len + s2len + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		nwstr[i] = s1[i];
		i++;
	}
	ii = 0;
	while (s2[ii] != '\0')
	{
		nwstr[i] = s2[ii];
		ii++;
		i++;
	}
	nwstr[i] = '\0';
	return (nwstr);
}
