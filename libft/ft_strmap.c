/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:14:37 by ehelmine          #+#    #+#             */
/*   Updated: 2020/07/02 10:08:02 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description Applies the function f to each character of the string given
** as argument to create a “fresh” new string (with malloc(3))
** resulting from the successive applications of f.
** Param. #1 The string to map.
** Param. #2 The function to apply to each character of s.
** Return value The “fresh” string created from the successive applications of
** f.
*/

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*nwstr;
	char	*ss;

	if (!(ss = (char *)malloc(sizeof(*ss) * (ft_strlen(s)) + 1)))
		return (NULL);
	ss = ft_strcpy(ss, s);
	i = 0;
	while (ss[i] != '\0')
	{
		ss[i] = f(ss[i]);
		i++;
	}
	if (!(nwstr = (char *)malloc(sizeof(*nwstr) * i + 1)))
		return (NULL);
	ft_strcpy(nwstr, ss);
	return (nwstr);
}
